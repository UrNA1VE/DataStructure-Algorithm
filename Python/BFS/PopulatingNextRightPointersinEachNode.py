# https://leetcode.com/problems/populating-next-right-pointers-in-each-node/


"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
        process = deque()
        process.append(root)
        process.append('#')
        while process:
            node = process.popleft()
            flag = 0
            if process[0] == '#':
                node.next = None
                process.popleft()
                flag = 1
            else:
                node.next = process[0]
            if node.left:
                process.append(node.left)
                process.append(node.right)
                if flag:
                    process.append('#')
        return root
