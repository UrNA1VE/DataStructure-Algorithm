# https://leetcode.com/problems/unique-paths-ii/

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if not obstacleGrid:
            return 0
        dp = [[0] * len(obstacleGrid[0]) for i in range(len(obstacleGrid))]
        dp[-1][-1] = 1
        for i in range(len(obstacleGrid) - 1, -1, -1):
            for j in range(len(obstacleGrid[0]) - 1, -1, -1):
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = 0
                elif i == len(obstacleGrid) - 1 and j == len(obstacleGrid[0]) - 1:
                    continue
                elif i == len(obstacleGrid) - 1:
                    dp[i][j] = dp[i][j + 1]
                elif j == len(obstacleGrid[0]) - 1:
                    dp[i][j] = dp[i + 1][j]
                else:
                    dp[i][j] = dp[i][j + 1] + dp[i + 1][j]
        return dp[0][0]
