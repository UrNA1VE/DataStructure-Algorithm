
# https://leetcode.com/problems/unique-binary-search-trees-ii/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        dp = {}
        def generate(i,j):
            if (i, j) in dp:
                return dp[(i, j)]
            if j-i < 0:
                res = [None]
            elif j-i == 0:
                res = [TreeNode(i)]
            else:
                res = []
                for k in range(i,j+1):
                    left = generate(i,k-1)
                    right = generate(k+1,j)
                    for l in left:
                        for r in right:
                            root = TreeNode(k)
                            root.left = l
                            root.right = r
                            res.append(root)

            dp[(i, j)] = res
            return res
        if n == 0:
            return []
        else:
            return generate(1,n)
