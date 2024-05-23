import numpy as np
import keyboard


class PIController:
    coefficient = 0.1

    def __init__(self):
        pass

    def get_input(self, state):
        (alpha1, alpha2) = (0, 0)
        if keyboard.is_pressed("left arrow"):
            alpha1 = 5
        elif keyboard.is_pressed("right arrow"):
            alpha1 = -5

        if keyboard.is_pressed("up arrow"):
            alpha2 = 5
        elif keyboard.is_pressed("down arrow"):
            alpha2 = -5
        return {"rudder": alpha1, "lift": alpha2}
