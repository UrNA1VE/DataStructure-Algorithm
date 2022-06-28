# https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.n_left = 1
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        if not nums:
            return nums
        root = Node(nums[-1])
        ans = [0]
        def dfs(node, val, counter):
            if val > node.val:
                counter += node.n_left
                if node.right:
                    return dfs(node.right, val, counter)
                else:
                    node.right = Node(val)
                    return counter
            else:
                node.n_left += 1
                if node.left:
                    return dfs(node.left, val, counter)
                else:
                    node.left = Node(val)
                    return counter

        for i in nums[-2::-1]:
            ans.append(dfs(root, i, 0))
        return ans[::-1]
