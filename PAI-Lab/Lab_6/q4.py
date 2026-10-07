prices = {"pen": 30, "notebook": 120, "bag": 1500, "calculator": 950,
"marker": 60}
cart = [("pen", 3), ("notebook", 2), ("marker", 1), ("pen", 2),
("eraser", 4), ("bag", 1), ("glue", 2)]

quantities = {}
for item, qty in cart:
    if item in quantities:
        quantities[item] += qty
    else:
        quantities[item] = qty
print(quantities)

unavailable = set(quantities)-set(prices)
print(sorted(unavailable))

line_total = {}
total = 0

for item, qty in quantities.items():
    if item in prices:
        line_total[item]=prices[item]*qty
        print(f"{item} x {qty} = {line_total[item]}")
        total+=line_total[item]
print("TOTAL:",total)
discount = 0
if total>1800:
    discount = (total/10)
    total -= discount
print("DISCOUNT:", discount)
print("AMOUNT TO PAY:",total)
    
highestlineTotal = max(line_total, key=line_total.get)
print("Highest line total:", highestlineTotal, line_total[highestlineTotal])
