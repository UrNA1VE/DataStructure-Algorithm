# https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/

class Solution:
    def minOperations(self, nums: List[int], numsDivide: List[int]) -> int:
        target = reduce(gcd, numsDivide)
        for i, num in enumerate(sorted(nums)):
            if num > target: break
            if target % num == 0:
                return i
        return -1
