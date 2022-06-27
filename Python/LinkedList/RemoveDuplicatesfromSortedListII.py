# https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        dummy = ListNode(-1)
        dummy.next = head
        pre, curr, nex = dummy, head, head.next
        
        while curr is not None and nex is not None:
            flag = False
            while nex is not None and curr.val == nex.val:
                flag = True
                nex = nex.next
            if not flag:
                pre = curr
            else:
                pre.next = nex
            curr = pre.next
            if curr is not None:
                nex = curr.next
        return dummy.next
            
            
