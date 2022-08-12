# https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/

class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        dp = [False, False, False, True]
        n = len(nums)
        for i in range(n):
            dp[i % 4] = False
            if i - 1 >= 0 and nums[i] == nums[i - 1]:
                dp[i % 4] |= dp[(i - 2) % 4]
            if i - 2 >= 0 and nums[i] == nums[i - 1] == nums[i - 2]:
                dp[i % 4] |= dp[(i - 3) % 4]
            if i - 2 >= 0 and nums[i] == nums[i - 1] + 1 == nums[i - 2] + 2:
                dp[i % 4] |= dp[(i - 3) % 4]
        return dp[(n - 1)%4]
            
        
