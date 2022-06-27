# https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return root
        traversal = []
        queue = [root]
        flag = True
        while queue:
            size = len(queue)
            current = []
            for i in range(size):
                node = queue.pop(0)
                if flag:
                    current.append(node.val)
                else:
                    current.insert(0, node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            traversal.append(current)
            flag = not flag
        return traversal
        
