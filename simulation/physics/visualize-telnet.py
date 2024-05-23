import numpy as np
import autopilot
import engine
import movement_equations
import time
import matplotlib.pyplot
from flightgear_python.fg_if import TelnetConnection
import pyproj
from geographiclib.geodesic import Geodesic
import time


class Utils:
    lat = 37.8625
    lon = -122.343

    @staticmethod
    def xy_to_lonlat(x, y):
        g = Geodesic.WGS84.Direct(Utils.lat, Utils.lon, -np.arctan(y/x if x != 0 else np.inf), np.linalg.norm([x, y]))
        return g['lon2'], g['lat2']


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

    coordinate_names = ["/position/longitude-deg", "/position/altitude-ft", "/position/latitude-deg", "/orientation/pitch-deg", "/orientation/roll-deg", "/orientation/heading-deg"]
    coordinate_factor = [1, 3.28084, 1, 180/np.pi, 180/np.pi, 180/np.pi]
    coordinate_zero = [0, 100, 0, 0, 0, 0]

    def __init__(self, physics_model=None, controller=None, speed=None, position=None):
        self.physics_model = physics_model
        self.controller = controller
        self.state = State() if speed is None and position is None else (State(v=speed) if position is None else State(x=position, v=speed))
        self.eng = None

    def set_coordinates(self, x):
        x_m = np.copy(x)
        x_m[[0, 2]] = Utils.xy_to_lonlat(*x_m[[0, 2]])
        for i in range(len(x_m)):
            self.eng.set_prop(self.coordinate_names[i], x_m[i]*self.coordinate_factor[i]+self.coordinate_zero[i])

    # Launch FG with fgfs.exe --telnet=socket,bi,60,localhost,5500,tcp --fdm=null --aircraft=MPK --airport=SP01
    def connect_to_fg(self):
        self.eng = TelnetConnection('localhost', 5500)
        self.eng.connect()
        self.set_coordinates(self.state.get_current()["x"])
        print("Initialized Model")

    def connect_controller(self, controller):
        self.controller = controller

    def connect_model(self, physics_model):
        self.physics_model = physics_model

    def simulate(self):
        # Control Loop
        print("Preparing...")
        #time.sleep(5)
        print("Ready")
        last_time = 0
        mt = np.zeros((5,3))
        cc = 0
        t1 = t2 = t3 = t4 = t5 = 0
        while True:
            t1 = time.time()
            params = self.controller.get_input(self.state)
            t2 = time.time()
            self.state.update(*self.physics_model.solve(self.state.get_current(), params))
            t3 = time.time()
            # Pause the Simulation for each timestep
            if self.state.get_current()["t"] - last_time > 0.03:
                t4 = time.time()
                last_time = self.state.get_current()["t"]
                # print(self.state.get_current()["x"])
                self.set_coordinates(self.state.get_current()["x"])
                t5 = time.time()
                print(np.average(mt, axis=0))
            mt[cc, :] = np.array([t2-t1, t3-t2, t5-t4])
            cc = (cc + 1) % 5


if __name__ == "__main__":
    plant = SimulinkPlant(physics_model=engine.BasicPhysicsModel(plane_model=movement_equations.PlanerModel()), speed=np.array([10, 0, 0, 0, 0, 0]), position=np.array([0, 0, 0, -0.5, 0, 0]))
    # Establishes a Connection
    plant.connect_to_fg()

    # Instantiates the controller
    plane_controller = autopilot.PIController()
    plant.connect_controller(plane_controller)

    # Control Loop
    plant.simulate()
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



