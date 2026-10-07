def factorial(k):
    fact = 1
    for i in range(1, k+1):
        fact *= i
    return fact
def combination(n, r):
    c = factorial(n)/((factorial(r))*factorial(n-r))
    return c
print(combination(10, 3))
print(combination(6, 2))
