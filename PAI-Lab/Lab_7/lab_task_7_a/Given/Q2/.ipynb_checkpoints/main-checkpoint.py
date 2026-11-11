# Lab Task 7 - Question 2 (starter code)
# TODO: import the shop package, the billing and inventory modules,
#       and is_valid_phone from shop.validators; also STOCK from shop.catalog
import shop
from shop import billing, inventory
from shop.validators import is_valid_phone
from shop.catalog import STOCK

def process_order(customer, phone, cart):
    """Bill one order, print it and return the amount paid (0 if rejected)."""
    if not is_valid_phone(phone):
        return 0
    else:
        rows, skipped, total = billing.make_bill(cart)
        print(rows)
        print(skipped)
    if total > 1500:
        discount, amountToPay = billing.apply_discount(total, 10)
    print(total)
    print(discount)
    print(amountToPay)
    inventory.update_stock(rows)
    return amountToPay
        


# (customer, phone, cart)
orders = [
    ("Ayesha", "0312-3456789", [("pen", 3), ("notebook", 2), ("calculator", 1), ("geometry box", 2)]),
    ("Bilal", "0300-12345", [("bag", 1)]),
    ("Hina", "0345-1112223", [("notebook", 5), ("marker", 2), ("glue", 1), ("geometry box", 1)]),
]

# TODO: print shop.SHOP_NAME, process every order, then print the sales of the day and the stock
print(shop.SHOP_NAME)
for cust, ph, cart in orders:
    sales += process_order(cust, ph, cart)
print(sales)
print(STOCK)