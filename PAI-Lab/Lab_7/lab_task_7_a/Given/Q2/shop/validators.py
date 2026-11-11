# GIVEN FILE - do not change it.
"""validators.py - checks customer details before billing."""

PHONE_LENGTH = 12  # e.g. 0312-3456789


def is_valid_phone(phone):
    """Return True if phone looks like 0312-3456789."""
    if len(phone) != PHONE_LENGTH:
        return False
    return phone[:2] == "03" and phone[:4].isdigit() and phone[4] == "-" and phone[5:].isdigit()


# runs only when this file is run directly: python shop/validators.py
if __name__ == "__main__":
    print("Testing validators...")
    print(is_valid_phone("0312-3456789"))  # True
    print(is_valid_phone("03123456789"))  # False: no dash
    print(is_valid_phone("0412-3456789"))  # False: does not start with 03
