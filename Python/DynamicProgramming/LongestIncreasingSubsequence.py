# https://leetcode.com/problems/longest-increasing-subsequence/

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        size = len(nums)
        dp = [0] * size
        dp[0] = 1
        ans = 1
        for i in range(1, size):
            max1 = 0
            for j in range(0, i):
                if nums[i] > nums[j]:
                    max1 = max(max1, dp[j] + 1)
            dp[i] = max(1, max1)
            if dp[i] > ans:
                ans = dp[i]
        return ans
