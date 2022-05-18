import yaml
import os
import numpy as np


class Uav:
    def __init__(self, r, surface_distance, angle, v_earth, v_air, rpm, current, voltage, temperature, *args, **kwargs):
        self.r = np.array(r) if len(np.array(r)) != 0 else np.array(r).reshape(1,)
        self.surface_distance = np.array(surface_distance) if len(np.array(surface_distance)) != 0 else np.array(surface_distance).reshape(1,)
        self.angle = np.array(angle) if len(np.array(angle)) != 0 else np.array(angle).reshape(1,)
        self.v_earth = np.array(v_earth) if len(np.array(v_earth)) != 0 else np.array(v_earth).reshape(1,)
        self.v_air = np.array(v_air) if len(np.array(v_air)) != 0 else np.array(v_air).reshape(1,)
        self.rpm = np.array(rpm) if len(np.array(rpm)) != 0 else np.array(rpm).reshape(1,)
        self.current = np.array(current) if len(np.array(current)) != 0 else np.array(current).reshape(1,)
        self.voltage = np.array(args) if len(np.array(args)) != 0 else np.array(args).reshape(1,)
        self.temperature = np.array(args) if len(np.array(args)) != 0 else np.array(args).reshape(1,)
        self.args = np.array(args) if len(np.array(args)) != 0 else np.array(args).reshape(1,)
        for i in kwargs.keys():
            exec("self." + str(i) + " = np.array(kwargs[i]) if len(np.array(kwargs[i])) != 0 else np.array(kwargs[i]).reshape(1,)")


class AutopilotModule:
    def __init__(self, output_params_num, type="tiltwing", scheme_path="./scheme.yaml"):
        """
        :param output_params_num:
        :param type:
        """
        self.output_params_num = output_params_num
        self.type = type
        self.scheme_path = scheme_path

        if os.path.isfile(self.scheme_path):
            with open(self.scheme_path, 'r') as file:
                self.makets = yaml.load(file, Loader=yaml.Loader)
                if self.makets is None:
                    self.makets = dict()
        else:
            with open(self.scheme_path, 'w+') as file:

                yaml.dump("ss", file)

    def data(self):
        pass
