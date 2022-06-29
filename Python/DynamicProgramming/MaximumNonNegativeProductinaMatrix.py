# https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/

class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        dp = copy.deepcopy(grid)
        for i in range(n - 1, - 1, - 1):
            for j in range(m - 1, -1, -1):
                if j == m - 1 and i == n - 1:
                    dp[i][j] = [grid[i][j], grid[i][j]]
                elif j == m - 1 and i < n - 1:
                    dp[i][j] = [grid[i][j] * dp[i + 1][j][0], grid[i][j] * dp[i + 1][j][0]]
                elif i == n - 1 and j < m - 1:
                    dp[i][j] = [grid[i][j] * dp[i][j + 1][0], grid[i][j] * dp[i][j + 1][0]]
                else:
                    res1 = max(max(grid[i][j] * dp[i][j + 1][0], grid[i][j] * dp[i][j + 1][1]), max(grid[i][j] * dp[i + 1][j][0], grid[i][j] * dp[i + 1][j][1]))
                    res2 = min(min(grid[i][j] * dp[i][j + 1][0], grid[i][j] * dp[i][j + 1][1]), min(grid[i][j] * dp[i + 1][j][0], grid[i][j] * dp[i + 1][j][1]))
                    dp[i][j] =[res2, res1]
        
        return dp[0][0][1] % 1000000007 if dp[0][0][1]  >= 0 else -1
