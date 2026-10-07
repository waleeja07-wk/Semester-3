def nth_term(a, n, d=1):
    a_n = a + (n-1)*(d)
    return a_n
def sum_ap(a, n, d=1):
    """
    Computes & returns the sum of first n terms of an Arithmetic progression.
    
    a -- First term
    d -- common difference (default = 1)
    """
    S_n = (n/2)*(2*(a) + (n-1)*(d))
    return S_n
print(nth_term(3, 10))
print(sum_ap(3, 10))
print(nth_term(3, 10, 4))
print(sum_ap(3, 10, 4))
