# https://leetcode.com/problems/increasing-triplet-subsequence/ 

class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        inf = float('inf')
        ans = [inf] * 2
        for i in range(len(nums)):
            if nums[i] <= ans[0]:
                ans[0] = nums[i]
            elif nums[i] <= ans[1]:
                ans[1] = nums[i]
            else:
                return True
        return False
