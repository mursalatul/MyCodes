# process 1
arr = [64, 25, 12 , 22,22, 11]
n = len(arr)
for i in range(n):
    min_number = arr[i]
    min_n_index = i
    for j in range(i+1, n):
        if arr[j] < min_number:
            min_number = arr[j]
            min_n_index = j
    arr[i], arr[min_n_index] = arr[min_n_index], arr[i]
print(arr)
#

#process 2
arr = [64, 25, 12 , 22,22, 11]
n = len(arr)
for i in range(n):
    min_index = arr.index(min(arr[i:]), i)
    arr[i] , arr[min_index] = arr[min_index], arr[i]
print(arr)
#