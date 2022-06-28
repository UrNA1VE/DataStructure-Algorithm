# https://leetcode.com/problems/path-sum-iii/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        dic = {0: 1}
        path = 0
        def helper(node, target, cur_sum, table):
            if not node:
                return
            cur_sum += node.val
            can_sum = cur_sum - target
            nonlocal path
            path += table.get(can_sum, 0)
            table[cur_sum] = table.get(cur_sum, 0) + 1
            helper(node.left, target, cur_sum, table)
            helper(node.right, target, cur_sum, table)
            table[cur_sum] -= 1
        helper(root, sum, 0, dic)
        return path
