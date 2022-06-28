# https://leetcode.com/problems/kth-smallest-element-in-a-bst/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        count = 0
        value = 0
        if not root:
            return root
        def inorder(node):
            nonlocal count, value
            if node.left:
                inorder(node.left)
            count += 1
            if count == k:
                value = node.val
            if node.right:
                inorder(node.right)
        inorder(root)
        return value
