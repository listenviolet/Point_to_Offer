# -*- coding:utf-8 -*-
class Solution:
    def jumpFloor(self, number):
        # write code here
        f = [i for i in range(number + 1)]
        f[0] = 1     
        if number == 0:
            return f[0]
        if number == 1: return f[1]
        for i in range(2, number + 1, 1):
            f[i] = f[i - 1] + f[i - 2]
        return f[number]

# 8. 跳台阶
# 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
# 求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。