import matlab.engine
import matplotlib.pyplot as plt
import numpy as np
import time


class SimulinkPlant:
    def __init__(self, modelName='mpk'):
        self.modelName = modelName  # The name of the Simulink Model (To be placed in the same directory as the Python Code)
        # Logging the variables
        self.yHist = 0
        self.tHist = 0

    def setControlAction(self, u):
        # Helper Function to set value of control action
        self.eng.set_param('{}/u'.format(self.modelName), 'value', str(u), nargout=0)

    def getHistory(self):
        # Helper Function to get Plant Output and Time History
        return self.eng.workspace['output'], self.eng.workspace['tout']

    def connectToMatlab(self):
        print("Starting matlab")
        self.eng = matlab.engine.start_matlab() #background=True

        print("Connected to Matlab")

        # Load the model
        self.eng.eval("model = '{}'".format(self.modelName), nargout=0)
        self.eng.eval("load_system(model)", nargout=0)

        # Initialize Control Action to 0
        self.setControlAction(0)
        print("Initialized Model")

        # Start Simulation and then Instantly pause
        self.eng.set_param(self.modelName, 'SimulationCommand', 'start', 'SimulationCommand', 'pause', nargout=0)
        self.yHist, self.tHist = self.getHistory()

    def connectController(self, controller):
        self.controller = controller

    def simulate(self):
        # Control Loop
        print("Preparing...")
        time.sleep(20)
        print("Ready")
        while (self.eng.get_param(self.modelName, 'SimulationStatus') != ('stopped' or 'terminating')):
            # Generate the Control action based on the past outputs
            u = self.controller.getControlEffort(self.yHist, self.tHist)

            # Set that Control Action
            self.setControlAction(u)

            # Pause the Simulation for each timestep
            self.eng.set_param(self.modelName, 'SimulationCommand', 'continue', nargout=0)
            self.eng.set_param(self.modelName, 'SimulationCommand', 'pause', nargout=0)

            self.yHist, self.tHist = self.getHistory()

    def disconnect(self):
        self.eng.set_param(self.modelName, 'SimulationCommand', 'stop', nargout=0)
        self.eng.quit()


class PIController:
    def __init__(self, history_length=1000):

        # Maintain a History of Variables
        self.yHist = []
        self.tHist = []
        self.uHist = np.zeros(history_length)
        self.ysum = 0
        self.py = 0
        self.history_length = history_length
        self.i = 0

    def getControlEffort(self, yHist, tHist):

        # Returns control action based on past outputs

        self.yHist = yHist
        self.tHist = tHist

        if (type(self.yHist) == float):
            y = self.yHist
        else:
            y = self.yHist[-1][0]

        if (type(self.tHist) == float):
            tt = self.tHist
        else:
            tt = self.tHist[-1][0]

        u = -y*5-self.ysum*5-(y-self.py)*5

        print(str(y) + " " + str(tt))
        self.uHist[self.i] = u
        self.ysum += y
        self.py = y
        self.i += 1
        self.i %= self.history_length
        return u


if __name__ == "__main__":
    plant = SimulinkPlant(modelName="mpk")
    # Establishes a Connection
    plant.connectToMatlab()

    # Instantiates the controller
    controller = PIController()
    plant.connectController(controller)

    # Control Loop
    plant.simulate()

    # Closes Connection to MATLAB
    plant.disconnect()