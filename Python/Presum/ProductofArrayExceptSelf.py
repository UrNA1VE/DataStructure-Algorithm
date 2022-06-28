# https://leetcode.com/problems/product-of-array-except-self/

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left = [1] * len(nums)
        right = [1] * len(nums)
        for i in range(1, len(nums)):
            left[i] = left[i - 1] * nums[i - 1]
            right[len(nums) - i - 1] = right[len(nums) - i] * nums[len(nums) - i]
        for i in range(len(nums)):
            left[i] = left[i] * right[i]
        return left
