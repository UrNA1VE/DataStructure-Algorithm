# https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        heap = []
        for i in nums1:
            for j in nums2:
                if len(heap) < k:
                    heapq.heappush(heap, [-i + (-j), i, j])
                else:
                    if heap and -heap[0][0] > i + j:
                        heapq.heappop(heap)
                        heapq.heappush(heap, [-i + (-j), i, j])
                    else:
                        break
        return [heapq.heappop(heap)[1:] for _ in range(k) if heap]
