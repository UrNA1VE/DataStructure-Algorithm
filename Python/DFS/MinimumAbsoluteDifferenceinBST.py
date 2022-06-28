# https://leetcode.com/problems/minimum-absolute-difference-in-bst/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        ret = 100000
        val = -1
        def dfs(node):
            nonlocal ret, val
            
            if node.left is not None:
                dfs(node.left)
            if val != -1:
                ret = min(ret, abs(val - node.val))
            val = node.val
            if node.right is not None:
                dfs(node.right)
            
        dfs(root)
        return ret
