# https://leetcode.com/problems/deepest-leaves-sum/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        process = []
        process.append(root)
        ans = root.val
        def bfs(process, res):
            next_process = []
            ans = 0
            while process:
                node = process.pop(0)
                if node.left is not None:
                    next_process.append(node.left)
                    ans += node.left.val
                if node.right is not None:
                    next_process.append(node.right)
                    ans += node.right.val
            if next_process == []:
                ans = res
            return next_process, ans
        while process:
            process, ans = bfs(process, ans)
        return ans
