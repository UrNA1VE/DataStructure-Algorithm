# https://leetcode.com/problems/n-ary-tree-level-order-traversal/

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:
            return []
        ret = []
        q = []
        q.append(root)
        next_q = []
        curr = []
        
        while True:
            while q:  
                node = q.pop(0)
                curr.append(node.val)
                for child in node.children:
                    next_q.append(child)
            ret.append(curr[::])
            curr = []
            q = next_q[::]
            next_q =[]
            if not q:
                return ret
        return ret
                
