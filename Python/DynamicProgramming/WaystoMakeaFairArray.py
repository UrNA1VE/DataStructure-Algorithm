# https://leetcode.com/problems/ways-to-make-a-fair-array/

class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        if not nums:
            return 0
        index = 1
        maxi = len(nums)
        res = 0
        odds = 0
        evens = 0
        flag = 0
        for i in range(1, maxi):
            if flag == 0:
                evens += nums[i]
                flag = 1
            else:
                odds += nums[i]
                flag = 0
        if odds == evens:
            res += 1
        flag = 0
        while index < maxi:
            if flag == 0:
                evens = evens - nums[index] + nums[index - 1]
                flag = 1
            else:
                odds = odds - nums[index] + nums[index - 1]
                flag = 0
            if odds == evens:
                res += 1
            index += 1
        return res
