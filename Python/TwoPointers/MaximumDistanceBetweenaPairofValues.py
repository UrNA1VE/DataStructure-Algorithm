# https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/

class Solution:
    def maxDistance(self, nums1, nums2) -> int:
        res = 0
        curr = 0
        i = 0
        j = 0
        while j < len(nums2) and i < len(nums1):
            if nums2[j] >= nums1[i]:
                curr = j - i
                j += 1
            elif nums2[j] < nums1[i] and j > i:
                i += 1
            elif nums2[j] < nums1[i] and j == i:
                i += 1
                j += 1
            res = max(curr, res)
        return res
        
