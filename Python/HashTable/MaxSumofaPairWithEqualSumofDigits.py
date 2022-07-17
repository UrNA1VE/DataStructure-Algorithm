# https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        
        cnt = defaultdict(list)
        
        def helper(num):
            curr = 0
            while num > 0:
                curr += num % 10
                num = num // 10
            return curr
        
        for num in nums:
            cnt[helper(num)].append(num)
        
        ret = -1
        for array in cnt.values():
            if len(array) >= 2:
                array.sort()
                ret = max(ret, array[-1] + array[-2])
        return ret
            
            
        
