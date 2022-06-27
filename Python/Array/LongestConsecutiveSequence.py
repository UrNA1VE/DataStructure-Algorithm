# https://leetcode.com/problems/longest-consecutive-sequence/

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        nums = set(nums)
        ans = 1
        for i in nums:
            if i - 1 not in nums:
                num = i
                cur = 1
                while num + 1 in nums:
                    num += 1
                    cur += 1
                ans = max(ans, cur)
        return ans
