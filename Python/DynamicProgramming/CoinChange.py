# https://leetcode.com/problems/coin-change/

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        inf = float('inf')
        dp = [inf] * (amount + 1)
        dp[0] = 0
        for i in coins:
            if i < amount:
                dp[i] = 1
        def helper(remain):
            if remain < 0:
                return -1
            if dp[remain] != inf:
                return dp[remain]
            else:
                min = inf
                for i in coins:
                    res = helper(remain - i)
                    if res != -1 and res < min:
                        min = res
                dp[remain] = min + 1 if min != inf else -1
            return dp[remain]

        return helper(amount)
