# https://leetcode.com/problems/first-missing-positive/

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        smallest = 1
        for i in range(n):
            if smallest in nums:
                smallest += 1
        return smallest
      
