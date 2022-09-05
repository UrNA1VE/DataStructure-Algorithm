# https://leetcode.com/problems/build-a-matrix-with-conditions/

class Solution:
    def buildMatrix(self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]) -> List[List[int]]:
        
        def ts(sorts):
            ans = []
            indeg = [0] * k
            graph = [[] for _ in range(k)]
            for u, v in sorts:
                indeg[v - 1] += 1
                graph[u - 1].append(v - 1)
            queue = [u for u in range(k) if indeg[u] == 0]
            while queue:
                u = queue.pop(0)
                ans.append(u + 1)
                
                for v in graph[u]:
                    indeg[v] -= 1
                    if indeg[v] == 0:
                        queue.append(v)
                        
            return ans
        
        rows = ts(rowConditions)
        cols = ts(colConditions)
        
        if len(rows) < k or len(cols) < k:
            return []
        
        ret = [[0] * k for _ in range(k)]
        row = {x: i for i, x in enumerate(rows)}
        col = {x: i for i, x in enumerate(cols)}
        for i in range(1, k + 1):
            ret[row[i]][col[i]] = i
        return ret
        
