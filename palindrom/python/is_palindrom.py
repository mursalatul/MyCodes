n = input("Targer: ") # taking input

if n == n[::-1]: # checking and printing answers. (n[::-1] = reverse n)
    print(n, "is palindrom")
else:
    print(n, "is not palindrom")