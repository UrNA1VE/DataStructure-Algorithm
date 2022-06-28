# https://leetcode.com/problems/move-zeroes/

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        count = 0
        n = len(nums)
        i = 0
        while i < n - count:
            if nums[i] != 0:
                i += 1
                continue
            else:
                count += 1
                a = nums[i]
                del nums[i]
                nums.append(a)
        return 
        """
        Do not return anything, modify nums in-place instead.
        """
        
