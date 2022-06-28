#. https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/ 

class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        if nums[left] < nums[right]:
            return nums[left]
        while right - left > 1:
            mid = (left + right) // 2
            if nums[mid] > nums[right]:
                left = mid
                right = right
            elif nums[mid] < nums[left]:
                right = mid
                left = left
        return min(nums[left], nums[right])
