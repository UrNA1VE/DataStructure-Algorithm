# https://leetcode.com/problems/merge-two-sorted-lists/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        ret = ListNode(-1)
        p = ret
        
        while list1 is not None and list2 is not None:
            if list1.val < list2.val:
                p.next = ListNode(list1.val)
                list1 = list1.next
            else:
                p.next = ListNode(list2.val)
                list2 = list2.next
            p = p.next
        if list1 is not None:
            p.next = list1
        if list2 is not None:
            p.next = list2
        return ret.next
        
