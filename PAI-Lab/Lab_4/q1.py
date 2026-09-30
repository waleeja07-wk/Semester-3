n = 500
sum = 0
for i in range(1, n):
    sum = 0
    for j in range(1, i):
        if(i%j==0):
            sum = sum + j
    if sum==i:
        print(i)
