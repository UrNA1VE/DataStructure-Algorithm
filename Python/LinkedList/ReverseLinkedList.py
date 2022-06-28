# https://leetcode.com/problems/reverse-linked-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        pre = None
        cur = head
        nex = cur.next
        while True:
            cur.next = pre
            pre = cur
            cur = nex
            if cur is None:
                break
            nex = nex.next
        return pre
