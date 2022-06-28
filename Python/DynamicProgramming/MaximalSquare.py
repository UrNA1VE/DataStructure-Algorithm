# https://leetcode.com/problems/maximal-square/

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        dp = [[0] * len(matrix[0]) for i in range(len(matrix))]
        ans = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if i == 0 or j == 0:
                    dp[i][j] = int(matrix[i][j])
                else:
                    if matrix[i][j] == '1':
                        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1
                    else:
                        dp[i][j] = 0
                ans = max(ans, dp[i][j])
        return ans ** 2
