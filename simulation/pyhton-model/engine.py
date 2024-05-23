import numpy as np


class BasicPhysicsModel:

    I = np.array([[0.05632, 0, 0], [0, 0.09867, 0], [0, 0, 0.04259]])
    m = 0.89
    step = 0.001
    current_state = {}

    def __init__(self, plane_model, **kwargs):

        self.plane_model = plane_model

        if len(kwargs.keys()) > 0:
            if "I" in kwargs.keys():
                self.I = kwargs["I"]
            if "m" in kwargs.keys():
                self.m = kwargs["m"]
            if "step" in kwargs.keys():
                self.step = kwargs["step"]

        self.invI = np.linalg.inv(self.I)
        self.limit = self.step**(-1)/10**2

    def solve(self, current, params):
        (x, v, a, r, w, b, t) = (current["x"][:3], current["v"][:3], current["a"][:3], current["x"][3:], current["v"][3:], current["a"][3:], current["t"])
        self.plane_model.update(self.m, self.I, x, v, a, r, w, b)
        a_new = -np.cross(w, v) + (self.plane_model.calc_movement(self.m, self.I, x, v, a, r, w, b, params))/self.m
        b_new = np.matmul(self.invI, -np.cross(w, (np.matmul(self.I, w))) + self.plane_model.calc_rotation(self.m, self.I, x, v, a, r, w, b, params))
        v_new = v + a_new * self.step
        w_new = w + b_new * self.step
        r_new = r + np.array([w_new[1]*np.sin(r[1]) + w_new[2]*np.cos(r[1]), w_new[0] - np.tan(r[0])*(w_new[1]*np.cos(r[1]) - w_new[2]*np.sin(r[1])), (w_new[1]*np.cos(r[1]) - w_new[2]*np.sin(r[1]))/np.cos(r[0])]) * self.step if np.cos(r[0]) != 0 else r + np.array([w_new[1]*np.sin(r[1]) + w_new[2]*np.cos(r[1]), w_new[0] - self.limit*(w_new[1]*np.cos(r[1]) - w_new[2]*np.sin(r[1])), (w_new[1]*np.cos(r[1]) - w_new[2]*np.sin(r[1]))/10E6]) * self.step
        x_new = x + np.matmul(np.array([[np.cos(r[0])*np.cos(r[2]), np.sin(r[2])*np.sin(r[1]) - np.sin(r[0])*np.cos(r[1])*np.cos(r[2]), np.sin(r[2])*np.cos(r[1]) + np.sin(r[0])*np.sin(r[1])*np.cos(r[2])], [np.sin(r[0]), np.cos(r[0])*np.cos(r[1]), -np.cos(r[0])*np.sin(r[1])], [-np.cos(r[0])*np.sin(r[2]), np.cos(r[2])*np.sin(r[1]) + np.sin(r[0])*np.cos(r[1])*np.sin(r[2]), np.cos(r[2])*np.cos(r[1]) - np.sin(r[0])*np.sin(r[1])*np.sin(r[2])]]), v_new) * self.step
        t_new = t + self.step
        return [np.concatenate((x_new, r_new)), np.concatenate((v_new, w_new)), np.concatenate((a_new, b_new)), t_new]
