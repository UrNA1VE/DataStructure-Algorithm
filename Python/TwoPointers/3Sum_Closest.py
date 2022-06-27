# https://leetcode.com/problems/3sum-closest/

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        sum3 = nums[0] + nums[1] + nums[2]
        diff3 = abs(sum3 - target)
        for i in range(1, len(nums) - 1):
            left = i - 1
            right = i + 1
            while left >= 0 and right < n:
                sum3_sub = nums[left] + nums[right] + nums[i]
                diff3_sub = abs(sum3_sub - target)
                if diff3_sub == 0:
                    return sum3_sub
                if diff3_sub < diff3:
                    diff3 = diff3_sub
                    sum3 = sum3_sub
                if sum3_sub > target:
                    left -= 1
                if sum3_sub < target:
                    right += 1  
        return sum3
