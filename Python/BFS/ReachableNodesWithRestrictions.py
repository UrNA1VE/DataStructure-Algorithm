# https://leetcode.com/problems/reachable-nodes-with-restrictions/


class Solution:
    def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
        graph = defaultdict(list)
        visited = set()
        res = set(restricted)
        queue = []
        queue.append(0)
        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])
        ret = 0  
        while queue:
            node = queue.pop(0)
            ret += 1
            visited.add(node)
            for nex in graph[node]:
                if nex not in visited and nex not in res:
                    queue.append(nex)
        return ret
            
