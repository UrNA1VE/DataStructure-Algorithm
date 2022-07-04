# https://leetcode.com/problems/solving-questions-with-brainpower/

class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        dp = [0 for _ in range(n)]
        dp[n - 1] = questions[n - 1][0]
        for i in range(n - 2, -1, -1):
            curr = 0 if i + questions[i][1] + 1 >= n else dp[i + questions[i][1] + 1]
            dp[i] = max(dp[i + 1], questions[i][0] + curr)
        return dp[0]
        
