def all_indexs(num: int, array: list) -> list:
    """this function will return a list of all indexs of a number"""
    res = [] # store the result
    for i in range(len(array)):
        if array[i] == num:
            res.append(i)
    return res
    
n = 1 # sample input number for find index
a = [1, 2, 3, 1, 2, 1, 1] # sample input array from which we have to find indexs
print(all_indexs(n, a)) # calling the function and printing the result