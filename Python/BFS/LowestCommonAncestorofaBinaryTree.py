# https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        father = {root: None}
        stack = [root]
        while p not in father or q not in father:
            cur = stack.pop(0)
            if cur.left:
                stack.append(cur.left)
                father[cur.left] = cur
            if cur.right:
                stack.append(cur.right)
                father[cur.right] = cur
        pfather = []
        while p:
            pfather.append(p)
            p = father[p]
        while q:
            if q in pfather:
                return q
            else:
                q = father[q]
