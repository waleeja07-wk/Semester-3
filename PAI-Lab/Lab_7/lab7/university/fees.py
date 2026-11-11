"""Fee rules."""

PER_CREDIT = 8000


def semester_fee(credits):
    """Return the fee for the given credit hours."""
    return credits * PER_CREDIT


def apply_scholarship(fee, percent):
    """Return the fee after taking percent off."""
    return fee - fee * percent / 100
