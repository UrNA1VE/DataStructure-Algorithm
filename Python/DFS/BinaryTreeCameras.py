# https://leetcode.com/problems/binary-tree-cameras/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minCameraCover(self, root: Optional[TreeNode]) -> int:
        visit = set([None])
        self.ret = 0
        def dfs(node, parent = None):
            if node:
                dfs(node.left, node)
                dfs(node.right, node)
                if (parent is None and node not in visit) or node.left not in visit or node.right not in visit:
                    self.ret += 1
                    visit.update(set([parent, node, node.left, node.right]))
        dfs(root)
        return self.ret
