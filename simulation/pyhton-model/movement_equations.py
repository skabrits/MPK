import numpy as np


class PlanerModel:

    coefficients = {"p1": 7.601E-07, "p2": -9.882E-06, "p3": 8.026E-05, "p4": 0.0001827, "p5": 0.003149, "q1": 0.01319, "q2": 0.0235, "a1": -0.0003282, "a2": 0.0008982, "b": -0.0001354, "d": -8.605E-05, "G": 9.81}
    OX = np.array([1, 0])
    limit = 1E6

    def __init__(self, **kwargs):
        try:
            if len(kwargs.keys()) > 0:
                for k in self.coefficients.keys():
                    self.coefficients[k] = kwargs[k]
        except KeyError as e:
            print(e)
            raise KeyError
        self.alpha = 0

    def update(self, m, I, x, v, a, r, w, b):
        self.alpha = (np.degrees(np.arcsin(np.clip(np.cross(v[:2]/np.linalg.norm(v[:2]), self.OX), -1.0, 1.0)) if np.linalg.norm(v[:2]) != 0 else 0) + 180) % 360 - 180

    def calc_movement(self, m, I, x, v, a, r, w, b, params):
        return np.array([-(self.coefficients["p1"]*self.alpha**4 + self.coefficients["p2"]*self.alpha**3 + self.coefficients["p3"]*self.alpha**2 + self.coefficients["p4"]*self.alpha + self.coefficients["p5"])*np.sign(v[0])*np.linalg.norm(v)**2-self.coefficients["G"]*m*np.sin(r[0]), (self.coefficients["q1"]*self.alpha + self.coefficients["q2"])*np.linalg.norm(v)**2-self.coefficients["G"]*m*np.cos(r[0])*np.cos(r[1]), self.coefficients["G"]*m*np.cos(r[0])*np.sin(r[1])])

    def calc_rotation(self, m, I, x, v, a, r, w, b, params):
        return np.array([0, self.coefficients["d"]*params["rudder"]*np.linalg.norm(v)**2, (self.coefficients["b"]*params["lift"] + self.coefficients["a1"]*self.alpha + self.coefficients["a2"])*np.linalg.norm(v)**2])
