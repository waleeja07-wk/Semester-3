units_consumed = 300
if units_consumed >=0 and units_consumed <=100:
    Total_bill = units_consumed * 5
elif units_consumed >100 and units_consumed <=200:
    Total_bill = units_consumed * 8
else:
    Total_bill = units_consumed * 12
if Total_bill > 2000:
    Total_bill += (Total_bill*0.15)

print("Total Electricity Bill: ", Total_bill)
