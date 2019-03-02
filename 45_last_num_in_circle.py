def LastRemaining_Solution(n, m):
    if n == 0 or m == 0: return -1
    arr = [i for i in range(n)]
    ind = 0
    while len(arr) > 1:
        tmp = 0
        while tmp < m - 1:
            ind = (ind + 1) % n
            tmp += 1
            continue
        print(arr)
        arr = arr[:ind] + arr[(ind + 1):]
        n = len(arr)
    return arr[0]


n = 5
m = 3
print(LastRemaining_Solution(n, m))