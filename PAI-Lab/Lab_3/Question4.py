correct_pin = "xxyy234@"
entered_pin = "xxyy234@"
balance = 10000
withdraw_amount = 4000
daily_limit = 5000
if entered_pin == correct_pin:
    if withdraw_amount > balance:
        print("Insufficient balance.")
    else:
        if(withdraw_amount > daily_limit):
            print("Daily withdrawal limit exceeded.")
        else:
            balance -= withdraw_amount
            print("Withdrawal Successful!", "\nNew Balance: ", balance)
else:
    print("Incorrect PIN. Access denied.")
