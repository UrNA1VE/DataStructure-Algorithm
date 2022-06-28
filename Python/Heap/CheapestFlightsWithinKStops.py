# https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        stack = [(0, src, K + 1)]
        edges = collections.defaultdict(dict)
        for i, j, k in flights:
            edges[i][j] = k
        while stack:
            cost, start, remain = heapq.heappop(stack)
            if start == dst:
                return cost
            if not remain:
                continue
            for end in edges[start]:
                heapq.heappush(stack, (cost + edges[start][end], end, remain - 1))
        return -1
