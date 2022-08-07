# https://leetcode.com/problems/count-number-of-bad-pairs/

class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        cnt = defaultdict(int)
        ret, n = 0, len(nums)
        for i in range(n):
            ret += i - cnt[i - nums[i]]
            cnt[i - nums[i]] += 1
        return ret
        
