# -*- coding:utf-8 -*-
class Solution:
    def movingCount(self, threshold, rows, cols):
        # write code here
        vis = [[0] * cols for _ in range(rows)]
        total = self.movingCountCore(threshold, rows, cols, 0, 0, vis)
        return total

    def movingCountCore(self, threshold, rows, cols, row, col, vis):
        count = 0
        if self.check(threshold, rows, cols, row, col, vis):
            vis[row][col] = 1
            count = 1 + self.movingCountCore(threshold, rows, cols, row - 1, col, vis) + self.movingCountCore(threshold, rows, cols, row + 1, col, vis) + self.movingCountCore(threshold, rows, cols, row, col - 1, vis) + self.movingCountCore(threshold, rows, cols, row, col + 1, vis)
        return count

    def check(self, threshold, rows, cols, row, col, vis):
        if row >= 0 and row < rows and col >= 0 and col < cols and self.digit(row) + self.digit(col) <= threshold and vis[row][col] == 0:
            return True
        return False
    
    def digit(self, number):
        total = 0
        while number > 0:
            mod = number % 10
            total += mod
            number = number // 10
        return total
        

solution = Solution()
print(solution.movingCount(10,1,100)) # 29
print(solution.movingCount(15,20,20)) # 359
        