# -*- coding:utf-8 -*-
import math
import heapq
class Solution:
    def __init__(self):
        self.nums=[]
        
    def Insert(self, num):
        # write code here
        heapq.heappush(self.nums, num)
        print(self.nums)
            
    def GetMedian(self, addition):
        # write code here
        mid = len(self.nums) // 2 + 1
        if len(self.nums) % 2 == 0:
            return (heapq.nlargest(mid, self.nums)[-1] + heapq.nsmallest(mid, self.nums)[-1]) / 2.0
        else:
            return heapq.nlargest(mid, self.nums)[-1]

solution = Solution()
i = 1.0
solution.Insert(i)
# solution.Insert(2.0)

print(solution.GetMedian('a'))