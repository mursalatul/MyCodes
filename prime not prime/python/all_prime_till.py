def if_prime(mm):
    if mm < 2 or (mm > 2 and mm % 2 == 0):
        return False
    till = int(mm ** 0.5) + 2
    for i in range(3, till, 2):
        if mm % i == 0 and mm != i:
            return False
    return True

"""all_prime_till is simple function which follow some simple algorithm to find
prime numbers till n(n is in count). in this function we mark a number and give it as argument in if_prime function which will tell us if the number is prime or not.

as we know, without 2 anyother even number is not prime. so we take only odd numbers as argument in all_prime function. """

def all_prime(n : int) -> list:
    prime_number = []  # result list ,contains only prime numbers from 2 to n
    if n < 2:
        return prime_number
    prime_number.append(2)
    for m in range(3, n + 1):
        if if_prime(m) == True:
            prime_number.append(m)
    return prime_number


print(*all_prime(1000000)) # example input