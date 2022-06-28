# https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

from heapq import heappush, heappop
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        z = []
        for i in range(n):
            for j in range(n):
                if len(z) < k:
                    heappush(z, -matrix[i][j])
                else:
                    a = z[0]
                    if -a > matrix[i][j]:
                        heappop(z)
                        heappush(z, -matrix[i][j])
        return -z[0]

        
