# https://leetcode.com/problems/number-of-people-aware-of-a-secret/

class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        dp = [0] * n
        dp[0] = 1
        canTell = 0
        known = 0
        for right in range(1, forget):
            i = right - delay
            if i >= 0:
                canTell += dp[i]
            dp[right] = canTell
        
        
        for right in range(forget, n):
            i = right - delay
            left = right - forget
            canTell += dp[i]
            canTell -= dp[left]
            dp[right] = canTell
        
        for i in range(n - forget, n):
            known += dp[i]
        return known % (10**9 + 7)
            
