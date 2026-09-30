x = 1.2
S = 0
n = 7
j = 1
for i in range(1, n):
    if i%2!=0:
        S = S +((pow(x,j)/j))
    else:
        S = S -((pow(x,j)/j))
    j=j+2
print(S) 
