"""fastest way to determine if a number(n) is prime or not
    here this function returns ture if n is prime or returns
    false if n is not a prime number"""

def prime(n : int) -> bool:
    if n < 2 or (n > 2 and n % 2 == 0): # if n is divisible by 2 or less then 2 it is obiously not a prime
                                        # number.
        return False
    till = int(n ** 0.5) + 2
    for i in range(3, till, 2): # using only odd numbers to check cause if n isnt divisible by 2, it cant be
                                # devisible by any other even numbers. every even number has a common divisor
                                # 2.here the range is sqrt of n + 2. cause if it is not a prime number then it
                                # must have a small divisorless then sqrt of n.So we dont need run the loop
                                # till n - 1. We also use + 2 after sqrt of n so that we can make sure that
                                #we will check almost every posible odd number and dont miss anything by mistake.
        if n % i == 0 and n != i:
            return False
    return True