# https://leetcode.com/problems/binary-tree-maximum-path-sum/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        ans = float('-inf')
        def bfs(node):
            nonlocal ans
            if node:
                left = 0
                right = 0
                if node.left:
                    left = max(bfs(node.left), 0)
                if node.right:
                    right = max(bfs(node.right), 0)
                ans = max(ans, left + right + node.val)
                return max(left, right) + node.val
        bfs(root)
        return ans
            
