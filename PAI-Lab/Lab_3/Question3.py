Coupon = "SAVE10"
Cart_Total = 800
Cart_Total_after_discount = Cart_Total
is_premium_member = False
match Coupon:
    case "SAVE10":
        discount = Cart_Total * 0.1
        Cart_Total_after_discount -= (discount)
    case "SUPER50":
        Cart_Total_after_discount -= 50
    case _:
        print("Invalid coupon code")
if is_premium_member or Cart_Total >= 1000:
    Shipping_Fee = 0
else:
    Shipping_Fee = 100
print("Cart Total: ", Cart_Total, "\nDiscount: ", discount, "\nCart Total After Discount: ", Cart_Total_after_discount)
print("Shipping Fee: ", Shipping_Fee)
print("Total Bill: ", Cart_Total_after_discount + Shipping_Fee)
