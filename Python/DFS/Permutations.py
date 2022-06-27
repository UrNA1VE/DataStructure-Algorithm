# https://leetcode.com/problems/permutations/

import copy
class Solution:
    def permute(self, nums):
        ans = []
        self.helper(nums, [], ans)
        return ans
        
    def helper(self, t, l, ans):
        if len(t) == 0:
            ans.append(l)
        for i in range(len(t)):
            self.helper(t[:i] + t[i+1: ], l + [t[i]], ans)
