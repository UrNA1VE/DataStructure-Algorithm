# https://leetcode.com/problems/3sum/

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        for i in range(len(nums) - 2):
            target = 0 - nums[i]
            left = i + 1
            right = len(nums) - 1
            if i == 0 or nums[i] != nums[i - 1]:
                while left < right:
                    s = nums[left] + nums[right]
                    if s == target:
                        res.append([nums[i], nums[left], nums[right]])
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                        left += 1
                        right -= 1
                    elif s < target:
                        left += 1
                    elif s > target:
                        right -= 1
        return res
