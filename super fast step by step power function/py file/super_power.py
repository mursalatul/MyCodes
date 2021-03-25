def super_power(a, n):
	res = 1
	binary = bin(n).replace("0b", "")
	for i in range(len(binary)):
		res *= res
		if binary[i] == "1":
			res *= a
	return res

print(super_power(int(input("a = ")), int(input("n = "))))