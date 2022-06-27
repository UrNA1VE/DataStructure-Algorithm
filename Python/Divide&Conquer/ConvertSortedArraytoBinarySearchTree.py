# https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        root = None
        n = len(nums)
        if n > 0:
            index = int(n/2)
            root = TreeNode(nums[index])
            root.left = self.sortedArrayToBST(nums[:index])
            root.right = self.sortedArrayToBST(nums[index + 1:])
        return root

        
