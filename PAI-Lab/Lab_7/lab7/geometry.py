"""Small helper functions for shapes."""
import math

UNITS = "cm"

print("geometry module is loading...")


def circle_area(r):
    """Return the area of a circle of radius r."""
    return math.pi * r * r


def rectangle_area(length, width):
    """Return the area of a rectangle."""
    return length * width


def hypotenuse(a, b):
    """Return the longest side of a right-angled triangle."""
    return math.sqrt(a * a + b * b)
