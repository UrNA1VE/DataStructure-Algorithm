# https://leetcode.com/problems/maximum-score-of-spliced-array/

class Solution:
    def maximumsSplicedArray(self, nums1: List[int], nums2: List[int]) -> int:
        sum1, sum2 = 0, 0
        for x in nums1:
            sum1 += x
        for x in nums2:
            sum2 += x
        
        s1, s2, first, second = 0, 0, 0, 0
        n = len(nums1)
        for i in range(n):
            first += (nums2[i] - nums1[i])
            second += (nums1[i] - nums2[i])
            first = max(first, 0)
            second = max(second, 0)
            s1 = max(s1, first)
            s2 = max(s2, second)
        return max(s1 + sum1, s2 + sum2)

