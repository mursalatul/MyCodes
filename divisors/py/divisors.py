def divisors(n : int) -> list:
    """divisor function returns a list of divisors of the number n"""
    list_of_divisors = []
    till = int(n ** 0.5)

    for i in range(1, till + 1):
        if n % i == 0: # if reminder = 0 then it is a divisor of n
            if n / i != i: # if reminder = 0 then both divisor and
                # quotient is divisor. if x / y = z and x % y == 0,
                # then both y and z if divisible by x
                list_of_divisors.append(i) # so we are taking both i
                list_of_divisors.append(n // i) # and n / i
            else: # sometimes i and n/i is a same number.in this case
                # we have to take one of them.
                list_of_divisors.append(i)

    list_of_divisors.sort() # have to sort cause it will return
    # unsorted result . int main list 4 = 1, 4, 2
    # after sort this, 4 = 1, 2, 4 which is more appropriate
    return list_of_divisors

print(divisors(10)) # example input

