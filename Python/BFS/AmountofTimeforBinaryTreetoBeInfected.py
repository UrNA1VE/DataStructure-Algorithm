# https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        graph = defaultdict(list)
        q = []
        q.append(root)
        while q:
            node = q.pop(0)
            if node.left:
                graph[node.left.val].append(node.val)
                graph[node.val].append(node.left.val)
                q.append(node.left)
            if node.right:
                graph[node.right.val].append(node.val)
                graph[node.val].append(node.right.val)
                q.append(node.right)
        
        q = []
        next_q = []
        visit = set()
        q.append(start)
        visit.add(start)
        ret = 0
        while True:
            while q:
                node = q.pop(0)
                for next_node in graph[node]:
                    if next_node not in visit:
                        next_q.append(next_node)
                        visit.add(next_node)
            
            q = next_q[::]
            next_q = []
            if not q: return ret
            ret += 1
        return ret
            
