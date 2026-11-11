"""Unit conversions."""


def c_to_f(c):
    """Celsius to Fahrenheit."""
    return c * 9 / 5 + 32


def km_to_miles(km):
    """Kilometres to miles."""
    return km * 0.621371


if __name__ == "__main__":
    print("Testing converter...")
    print(c_to_f(100))       # 212.0
    print(km_to_miles(10))   # 6.21371
