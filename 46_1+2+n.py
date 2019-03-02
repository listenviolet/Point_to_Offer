# -*- coding:utf-8 -*-
class Solution:
    def Sum_Solution(self, n):
        # write code here 
        result = n 
        temp = n > 0 and self.Sum_Solution(n - 1)
        result += temp
        return result

# 利用逻辑与的短路特性实现递归终止