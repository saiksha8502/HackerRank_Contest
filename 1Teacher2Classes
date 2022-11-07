def mergeArrays(arr1, arr2, n1, n2, arr3):
    i = 0
    j = 0
    k = 0
    while i<n1 and j <n2:
        if arr1[i] < arr2[j]:
            arr3[k] = arr1[i]
            k += 1
            i += 1
        else:
            arr3[k] = arr2[j]
            k += 1
            j += 1
    while i < n1:
        arr3[k] = arr1[i]
        k += 1
        i += 1
    while j < n2:
        arr3[k] = arr2[j]
        k += 1
        j += 1

n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))
c = [0]*(n+m)
mergeArrays(a, b, n, m, c)
for i in range(n+m):
    print(c[i], end=" ")
