arr = [4, 3,4,4,3,3,2,2,1, 5, 1, 2,4]
n = len(arr)
for i in range(1, n): # i = 3
    if arr[i] < arr[i - 1]:
        j = i - 1
        while j >= 0:
            if arr[j] < arr[i]:
                temp = arr[i]
                arr.pop(i)
                arr.insert(j + 1, temp)
                break
            if j == 0:
                temp = arr[i]
                arr.pop(i)
                arr.insert(j, temp)
                break
            else:
                j -= 1
print(arr)
