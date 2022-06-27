# https://leetcode.com/problems/remove-nth-node-from-end-of-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        count = 0
        nodes = []
        while head:
            nodes.append(head)
            count += 1
            head = head.next
        if count == 1 and n == 1:
            return None
        if count == n:
            return nodes[1]
        if n == 1:
            nodes[-2].next = None
            return nodes[0]
        else:
            pre = nodes[count - n - 1]
            nex = nodes[count - n + 1]
            pre.next = nex
            return nodes[0]
