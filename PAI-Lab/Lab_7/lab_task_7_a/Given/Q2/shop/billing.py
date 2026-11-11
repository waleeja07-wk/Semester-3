"""billing.py - bill calculations for the shop. (YOU write this module)"""
# TODO: import PRICES from the catalog module and can_sell from the inventory module
from shop.catalog import PRICES
from shop.inventory import can_sell

def make_bill(cart):
    """Split the cart into billed rows and skipped items.

    Each billed row is a tuple (item, qty, price, amount).
    Returns (rows, skipped, total).
    """
    rows = []
    skipped = []
    total = 0
    for item ,qty in cart:
        if can_sell(item, qty):
            price = PRICE[item]
            amount = price * qty
            rows.append(item, qty, price, amount)
            total += amount
        else:
            skipped.append(item)
    return (rows, skipped, total)

def apply_discount(total, percent):
    """Return (discount, amount to pay) after taking percent off total."""
    discount = total * (percent/100)
    return (discount, amount-discount)