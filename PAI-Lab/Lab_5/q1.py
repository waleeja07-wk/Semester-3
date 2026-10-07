def approximate_sqrt(n, guess = 1.0, steps = 8):
    """
        Approximate the square root of n.
        
        Uses babaylonian method for approximation.
        
        n -- number whose square root has to be found.
        guess -- Initial guess (default = 1,0), updates as the program proceeds.
        steps -- The number of times the guess need to be updated (default = 8).
    
        The functions returns the final approximated value.
    """
    for i in range(steps):
        guess = (guess + n / guess)/2
    return guess
print(approximate_sqrt(49))
print(approximate_sqrt(2, 1.0, 10))
help(approximate_sqrt)
