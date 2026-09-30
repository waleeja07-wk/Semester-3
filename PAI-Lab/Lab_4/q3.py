m = 40
greatest = 0
greatm = 0
for i in range(1, m+1):
    current = i       
    stepCount = 0
    while current != 1:
        if current % 2 == 0:
            current = current // 2   
        else:
            current = 3 * current + 1
        stepCount = stepCount + 1
    if stepCount > greatest:
        greatest = stepCount
        greatm = i      
print(greatm)
print(greatest)
