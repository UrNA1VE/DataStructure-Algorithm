# https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        head = None
        if len(preorder) > 0 and len(inorder) > 0:
            head = TreeNode(preorder[0])
            index = inorder.index(preorder[0])
            del preorder[0]
            head.left = self.buildTree(preorder, inorder[: index])
            head.right = self.buildTree(preorder, inorder[index + 1:])
        return head
        
