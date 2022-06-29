# https://leetcode.com/problems/furthest-building-you-can-reach/

class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        pq = []
        for i in range(1, len(heights)):
            d = heights[i] - heights[i - 1]
            if d > 0:
                bricks -= d
                heapq.heappush(pq, -d)
                if bricks < 0:
                    ladders -= 1
                    bricks -= heapq.heappop(pq)
                    if bricks < 0 or ladders < 0:
                        return i - 1
        return len(heights) - 1
