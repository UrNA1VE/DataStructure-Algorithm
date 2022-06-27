# https://leetcode.com/problems/minimum-path-sum/

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid:
            return 
        rows = len(grid)
        cols = len(grid[0])
        dp = [[0] * cols for i in range(rows)]
        dp[-1][-1] = grid[-1][-1]
        for i in range(1, cols):
            dp[-1][cols - i - 1] = grid[-1][cols - i - 1] + dp[-1][cols - i]
        for i in range(1, rows):
            dp[rows - i - 1][-1] = grid[rows - i - 1][-1] + dp[rows - i][-1]
        for i in range(1, rows):
            for j in range(1, cols):
                dp[rows - i - 1][cols - j - 1] = min(dp[rows - i - 1][cols - j], dp[rows - i][cols - j - 1]) + grid[rows - i - 1][cols - j - 1]
                
        return dp[0][0]
