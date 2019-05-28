def InversePairs(self, data):
    # write code here
    count = 0
    copy = sorted(data)
    for i in range(len(copy)):
        # cur = copy[i]
        pos = data.index(copy[i])
        count += pos
        data.pop(pos)
    return count % 1000000007

# 运行超时:您的程序未能在规定时间内运行结束，请检查是否循环有错或算法复杂度过大。
# case通过率为50.00%