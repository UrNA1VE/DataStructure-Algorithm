# https://leetcode.com/problems/binary-tree-inorder-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if not root:
            return root
        def helper(node):
            if node.left:
                helper(node.left)
            res.append(node.val)
            if node.right:
                helper(node.right)
        helper(root)
        return res
