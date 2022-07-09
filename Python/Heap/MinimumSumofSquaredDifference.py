# https://leetcode.com/problems/minimum-sum-of-squared-difference/

class Solution:
    def minSumSquareDiff(self, nums1: List[int], nums2: List[int], k1: int, k2: int) -> int:
        h = [-abs(x - y) for x, y in zip(nums1, nums2)]
        heapify(h)
        n = len(nums1)
        all_k = k1 + k2
        all_sum = sum(h)
        if abs(all_sum) < all_k: return 0
        while all_k > 0:
            gap = max(all_k // n, 1)
            d = -heappop(h)
            d -= gap
            all_k -= gap
            heappush(h, - d)
        return sum(pow(i, 2) for i in h)
        
