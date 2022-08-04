# https://leetcode.com/problems/longest-cycle-in-a-graph/

class Solution:
    def longestCycle(self, edges: List[int]) -> int:
        n = len(edges)
        visited = {}
        seen = [False for _ in range(n)]
        ret = -1
        def dfs(node, cnt):
            nonlocal ret
            if node == -1:
                return
            elif not seen[node]:
                if node in visited:
                    ret = max(ret, cnt - visited[node])
                else:
                    visited[node] = cnt
                    next_node = edges[node]
                    dfs(next_node, cnt + 1)
                    visited.pop(node)
                seen[node] = True
        for i in range(n):
            dfs(i, 0)
        return ret
        
        
