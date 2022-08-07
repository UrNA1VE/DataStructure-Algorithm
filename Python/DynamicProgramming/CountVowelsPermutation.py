# https://leetcode.com/problems/count-vowels-permutation/

class Solution:
    def countVowelPermutation(self, n: int) -> int:
        dp = [1 for _ in range(5)]
        next_dp = [1 for _ in range(5)]
        for i in range(1, n):
            next_dp[0] = dp[1]
            next_dp[1] = dp[0] + dp[2]
            next_dp[2] = sum(dp) - dp[2]
            next_dp[3] = dp[2] + dp[4]
            next_dp[4] = dp[0]
            for j in range(5):
                dp[j] = next_dp[j]
        return sum(dp) % int(1e9 + 7)
            
        
        
