# -*- coding:utf-8 -*-
class Solution:
    def maxInWindows(self, num, size):
        # write code here
        maxwindow = []
        if not num or size == 0 or size > len(num): return []
        maxwindow.append(max(num[:size]))
        for i in range(1, len(num) - size + 1, 1):
            pre = num[i - 1]
            pre_max = maxwindow[i - 1]
            cur = num[i + size - 1]
            
            if cur >= pre_max:
                maxwindow.append(cur)
            elif cur < pre_max:
                if pre == pre_max:
                    maxwindow.append(max(num[i: i + size]))
                elif pre < pre_max:
                    maxwindow.append(maxwindow[i - 1])
        return maxwindow

num = [2,3,4,2,6,2,5,1]
size = 3
solution = Solution()
maxwindow = solution.maxInWindows(num, size)
print(maxwindow)