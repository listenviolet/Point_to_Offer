# -*- coding:utf-8 -*-
class Solution:
    def pow(self, base, exponent):
        tmp = 1
        while(exponent > 0):
            tmp *= base
            exponent -= 1
        return tmp
    def Power(self, base, exponent):
        # write code here
        if base == 0: return 0
        if exponent == 0: return 1
        if exponent < 0:
            res = self.pow(base, -1 * exponent)
            return 1.0 / res
        return self.pow(base, exponent)

solution = Solution()
base = 2
exponent = 3
print(solution.Power(base, exponent))