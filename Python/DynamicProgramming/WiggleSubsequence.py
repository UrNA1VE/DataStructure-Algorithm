# https://leetcode.com/problems/wiggle-subsequence/ 

import numpy as np
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        dp = [[0] * len(nums) for _ in nums]
        for i in range(len(nums)):
            for j in range(i, len(nums)):
                if i == j == 0:
                    dp[i][j] = [1, 1]
                elif i == j:
                    dp[i][j] = [1, 1]
                    for k in range(i):
                        if nums[i] > nums[k]:
                            dp[i][j][0] = max(dp[i][j][0], dp[k][i])
                        elif nums[i] < nums[k]:
                            dp[i][j][1] = max(dp[i][j][1], dp[k][i])
                else:
                    if nums[j] > nums[i]:
                        dp[i][j] = dp[i][i][1] + 1
                    elif nums[j] < nums[i]:
                        dp[i][j] = dp[i][i][0] + 1
            dp[i][i] = max(dp[i][i])
        return np.max(dp)
