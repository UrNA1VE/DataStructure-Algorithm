# https://leetcode.com/problems/validate-binary-search-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        output = []
        if not root:
            return True
        if not root.left and not root.right:
            return True

        def inorder(node):
            if node.left:
                inorder(node.left)
            output.append(node.val)
            if node.right:
                inorder(node.right)
        inorder(root)
        for i in range(len(output) - 1):
            if output[i] >= output[i + 1]:
                return False
        return True
