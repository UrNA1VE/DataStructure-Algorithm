# https://leetcode.com/problems/binary-trees-with-factors/

import numpy as np
class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        arr.sort()
        dp = {value: 1 for value in arr}
        for i in range(len(arr)):
            for j in range(i):
                quotient = arr[i] / arr[j]
                if quotient in dp:
                    dp[arr[i]] += dp[arr[j]] * dp[quotient]
        return int(sum(dp.values()) % (1e9 + 7))
