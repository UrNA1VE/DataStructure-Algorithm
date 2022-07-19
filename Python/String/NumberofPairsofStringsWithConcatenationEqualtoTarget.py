# https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/

class Solution:
    def numOfPairs(self, nums: List[str], target: str) -> int:
        
        def helper(s1, s2, start, m):
            if s1 == s2[start: start + m]:
                return True
            return False
        
        prefix = [0] * 101
        suffix = [0] * 101
        pre = suf = False
        n = len(target)
        ret = 0
        for num in nums:
            m = len(num)
            pre = helper(num, target, 0, m)
            suf =  helper(num, target, n - m, m)
            if pre:
                ret += suffix[n - m]
            if suf:
                ret += prefix[n - m]
            if pre:
                prefix[m] += 1
            if suf:
                suffix[m] += 1
            pre = suf = False
        return ret
            
            
