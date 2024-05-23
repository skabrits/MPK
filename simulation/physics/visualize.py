import numpy as np
import autopilot
import engine
import movement_equations
import time
import matplotlib.pyplot
from flightgear_python.fg_if import FDMConnection
import pyproj
from geographiclib.geodesic import Geodesic
import time
import keyboard
import sys
import psutil
import subprocess


class Utils:
    lat = 37.8625
    lon = -122.343

    @staticmethod
    def xy_to_lonlat(x, y):
        g = Geodesic.WGS84.Direct(Utils.lat, Utils.lon, -np.arctan(y/x if x != 0 else np.inf), np.linalg.norm([x, y]))
        return np.radians(g['lon2']), np.radians(g['lat2'])


class State:
    history = []
    current = {"x": np.zeros((6,)), "v": np.zeros((6,)), "a": np.zeros((6,)), "t": 0}
    history_length = 1000
    length = 0

    def __init__(self, x=None, v=None, a=None, t=0, history_length=1000):
        if a is None:
            a = np.array([0 for i in range(6)])
        if v is None:
            v = np.array([0 for i in range(6)])
        if x is None:
            x = np.array([0 for i in range(6)])
        self.current["x"] = x
        self.current["v"] = v
        self.current["a"] = a
        self.current["t"] = t
        self.history_length = history_length

    def update(self, x, v, a, t):
        self.history.append(self.current.copy())
        self.current["x"] = x
        self.current["v"] = v
        self.current["a"] = a
        self.current["t"] = t

        self.current["x"][3:] = self.current["x"][3:] % (2*np.pi)

        if self.length >= self.history_length:
            self.history.pop(0)
        elif self.history_length != -1:
            self.length += 1

    def get_current(self):
        return self.current

    def get_history(self):
        return self.history


class SimulinkPlant:

    coordinate_names = ["lon_rad", "alt_m", "lat_rad", "theta_rad", "phi_rad", "psi_rad"]
    coordinate_factor = [1, 1, 1, 1, 1, 1]
    coordinate_zero = [0, 0, 0, 0, 0, 0]

    def __init__(self, physics_model=None, controller=None, speed=None, position=None):
        self.physics_model = physics_model
        self.controller = controller
        self.state = State() if speed is None and position is None else (State(v=speed) if position is None else State(x=position, v=speed))
        self.eng = None

    def set_coordinates(self, fdm_data, event_pipe):
        if event_pipe.child_poll():
            x_m, = event_pipe.child_recv()
            x_m[[0, 2]] = Utils.xy_to_lonlat(*x_m[[0, 2]])
            for i in range(len(x_m)):
                fdm_data[self.coordinate_names[i]] = x_m[i]*self.coordinate_factor[i]+self.coordinate_zero[i]
        return fdm_data

    # Launch FG with fgfs.exe --max-fps=30 --native-fdm=socket,out,30,localhost,5501,udp --native-fdm=socket,in,30,localhost,5502,udp --fdm=null --aircraft=MPK --airport=SP01
    def connect_to_fg(self):
        self.eng = FDMConnection(fdm_version=24)  # May need to change version from 24
        self.eng.connect_rx('localhost', 5501, self.set_coordinates)
        self.eng.connect_tx('localhost', 5502)
        self.eng.start()
        self.eng.event_pipe.parent_send((self.state.get_current()["x"],))
        print("Initialized Model")

    def connect_controller(self, controller):
        self.controller = controller

    def connect_model(self, physics_model):
        self.physics_model = physics_model

    def simulate(self):
        # Control Loop
        print("Preparing...")
        time.sleep(5)
        print("Ready")
        last_time = 0
        while not keyboard.is_pressed("q"):
            params = self.controller.get_input(self.state)
            self.state.update(*self.physics_model.solve(self.state.get_current(), params))
            # Pause the Simulation for each timestep
            if self.state.get_current()["t"] - last_time > 0.0001:
                last_time = self.state.get_current()["t"]
                # print(self.state.get_current()["x"])
                self.eng.event_pipe.parent_send((self.state.get_current()["x"],))


if __name__ == "__main__":
    if "fgfs.exe" not in (p.name() for p in psutil.process_iter()):
        subprocess.Popen(['C:/Program Files/FlightGear 2020.3/bin/fgfs.exe', '--max-fps=30', '--native-fdm=socket,out,30,localhost,5501,udp', '--native-fdm=socket,in,30,localhost,5502,udp', '--fdm=null', '--aircraft=MPK', '--airport=SP01'])
        print("started fg")
        time.sleep(30)
    print("proceeding to sim")
    plant = SimulinkPlant(physics_model=engine.BasicPhysicsModel(plane_model=movement_equations.PlanerModel()), speed=np.array([10, 0, 0, 0, 0, 0]), position=np.array([0, 100, 0, -0.5, 0, 0]))
    # Establishes a Connection
    plant.connect_to_fg()

    # Instantiates the controller
    plane_controller = autopilot.PIController()
    plant.connect_controller(plane_controller)

    # Control Loop
    plant.simulate()

    sys.exit()
    # e = engine.BasicPhysicsModel(plane_model=movement_equations.PlanerModel())
    # state = State(x=np.array([0, 0, 0, 0, 0, 0]), v=np.array([10, 0, 0, 0, 0, 0]), history_length=50000)
    #
    # for i in range(state.history_length):
    #     state.update(*e.solve(state.get_current(), {"rudder": 0, "lift": 0}))
    # import matplotlib
    # matplotlib.use('TkAgg')
    # fig, ax = matplotlib.pyplot.subplots(4, sharex=True)
    # ax[0].plot([i["t"] for i in state.get_history()], [i["x"][0] for i in state.get_history()])
    # ax[0].set_title('x(t)')
    # ax[1].plot([i["t"] for i in state.get_history()], [i["x"][1] for i in state.get_history()])
    # ax[1].set_title('z(t)')
    # ax[2].plot([i["t"] for i in state.get_history()], [np.degrees((i["x"][3] + np.pi) % (2*np.pi) - np.pi) for i in state.get_history()])
    # ax[2].set_title('theta(t)')
    # ax[3].plot([i["t"] for i in state.get_history()], [(np.degrees(np.arcsin(np.clip(np.cross(i["v"][0:2]/np.linalg.norm(i["v"][0:2]), np.array([1,0])), -1.0, 1.0)) if np.linalg.norm(i["v"][0:2]) != 0 else 0) + 180) % 360 - 180 for i in state.get_history()])
    # ax[3].set_title('v_dir(t)')
    #
    # fig1, ax1 = matplotlib.pyplot.subplots(4, sharex=True)
    # ax1[0].plot([i["t"] for i in state.get_history()], [i["v"][0] for i in state.get_history()])
    # ax1[0].set_title('v_x(t)')
    # ax1[1].plot([i["t"] for i in state.get_history()], [i["v"][1] for i in state.get_history()])
    # ax1[1].set_title('v_z(t)')
    # ax1[2].plot([i["t"] for i in state.get_history()], [i["a"][0] for i in state.get_history()])
    # ax1[2].set_title('a_x(t)')
    # ax1[3].plot([i["t"] for i in state.get_history()], [i["a"][1] for i in state.get_history()])
    # ax1[3].set_title('a_z(t)')
    #
    # fig2, ax2 = matplotlib.pyplot.subplots(2, sharex=True)
    # ax2[0].plot([i["t"] for i in state.get_history()], [i["v"][5] for i in state.get_history()])
    # ax2[0].set_title('v_o(t)')
    # ax2[1].plot([i["t"] for i in state.get_history()], [i["a"][5] for i in state.get_history()])
    # ax2[1].set_title('a_o(t)')
    #
    # matplotlib.pyplot.show()



