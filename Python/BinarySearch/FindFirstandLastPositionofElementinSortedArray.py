# https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        low, high = 0, len(nums) - 1
        first = -1
        last = -1
        while low <= high:
            mid = (low + high) // 2
            if nums[mid] == target:
                i, j = mid, mid
                while nums[i] == target and i >= 0:
                    i -= 1
                first = i + 1
                while nums[j] == target and j < len(nums):
                    j += 1
                    if j >= len(nums):
                        break
                last = j - 1
                return [first, last]
            else:
                if nums[mid] < target:
                    low = mid + 1
                else:
                    high = mid - 1
        return [first, last]
