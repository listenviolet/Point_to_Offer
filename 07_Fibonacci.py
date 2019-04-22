# -*- coding:utf-8 -*-
class Solution:
    def Fibonacci(self, n):
        # write code here
        f = [i for i in range(n + 1)]
        if n == 0: return f[0]
        if n == 1: return f[1]
        for i in range(2, n + 1, 1):
            f[i] = f[i - 1] + f[i - 2]
        return f[n]