# https://leetcode.com/problems/symmetric-tree/


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        else:
            return self.check(root.left, root.right)
    
    def check(self, left, right):
        if not left and not right:
            return True
        elif not left or not right:
            return False
        elif left.val == right.val:
            outer = self.check(left.left, right.right)
            inner = self.check(left.right, right.left)
            return outer and inner
        else:
            return False
        
