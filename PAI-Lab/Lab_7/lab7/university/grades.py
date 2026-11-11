"""Grading rules."""


def grade(marks):
    """Return the letter grade for marks out of 100."""
    if marks >= 85:
        return "A"
    elif marks >= 70:
        return "B"
    elif marks >= 50:
        return "C"
    return "F"
