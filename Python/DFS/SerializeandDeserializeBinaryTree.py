# https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        if not root:
            return None
        tree_left = self.serialize(root.left)
        tree_right = self.serialize(root.right)
        return str(root.val) + ',' + str(tree_left) + ',' + str(tree_right)

    def deserialize(self, data):
        if not data:
            return
        tree_list = data.split(',')
        def traversal():
            if not tree_list:
                return
            node_next = tree_list.pop(0)
            if node_next == 'None':
                return
            node_new = TreeNode(int(node_next))
            node_new.left = traversal()
            node_new.right = traversal()
            return node_new
        return traversal()

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
