def multipliers(n):
    mul = [] # result store
    j = int(n ** 0.5) # stop point
    for i in range(1, j + 1):
        if n % i == 0:
            if i != n/i:
                mul.append(i)
                mul.append(int(n/i))
            else: # if i and n/i both are some we need to import just one for overcome date repitation.
                mul.append(i)
    mul.sort() # sort for a better look
    return mul

n = int(input())
print(*multipliers(n))
