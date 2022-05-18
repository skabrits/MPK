import yaml
import os

class Uav:
    def __init__(self, ):
        pass

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