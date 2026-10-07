def is_pythagorean(a, b, c):
    t1 = (a)*(a)+(b)*(b)
    t2 = (c)*(c)
    if t1==t2:
        return True
    return False
count = 0
for i in range(1, 31):
    for j in range(1, 31):
        for k in range(1, 31):
            if(i<=j and j<=k and k<=30):
                if is_pythagorean(i, j, k):
                    print(f"{i}, {j}, {k}")
                    count +=1
        
print(count)
