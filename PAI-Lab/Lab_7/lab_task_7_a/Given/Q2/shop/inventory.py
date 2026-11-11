# GIVEN FILE - do not change it.
"""inventory.py - stock checks for the shop."""
from shop.catalog import PRICES, STOCK


def can_sell(item, qty):
    """Return True if the item is sold here and enough units are in stock."""
    return item in PRICES and STOCK[item] >= qty


def update_stock(rows):
    """Reduce STOCK for every billed row (item, qty, price, amount)."""
    for item, qty, price, amount in rows:
        STOCK[item] = STOCK[item] - qty
