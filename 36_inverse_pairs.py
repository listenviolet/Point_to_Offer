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