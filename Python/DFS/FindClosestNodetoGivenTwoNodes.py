# https://leetcode.com/problems/find-closest-node-to-given-two-nodes/

class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        
        def dfs(node, arr, cnt):
            if node != -1 and arr[node] == -1:
                next_node = edges[node]
                arr[node] = cnt
                dfs(next_node, arr, cnt + 1)
        
        n1 = [-1 for i in range(len(edges))]
        n2 = [-1 for i in range(len(edges))]
        dfs(node1, n1, 0)
        dfs(node2, n2, 0)
        
        ret = -1
        MAX = float("inf")
        for i in range(len(edges)):
            if n1[i] != -1 and n2[i] != -1:
                
                curr = max(n1[i], n2[i])
                if curr < MAX:
                    MAX = curr
                    ret = i
        return ret
                    
