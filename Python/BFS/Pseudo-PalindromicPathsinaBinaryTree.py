# https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        cnt = defaultdict(int)
        ret = 0
        def check(count):
            flag = False
            for key in count:
                if count[key] % 2 == 1:
                    if not flag:
                        flag = True
                    else:
                        return False
            return True
                    
            
        
        def dfs(node, count):
            nonlocal ret
            count[node.val] += 1
            if not node.left and not node.right:
                if check(count):
                    ret += 1
            if node.left:
                dfs(node.left, count)
            if node.right:
                dfs(node.right, count)
            count[node.val] -= 1
        dfs(root, cnt)
        return ret
        
