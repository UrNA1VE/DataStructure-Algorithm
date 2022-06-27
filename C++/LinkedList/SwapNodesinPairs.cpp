// https://leetcode.com/problems/swap-nodes-in-pairs/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* ret = new ListNode(-1);
        ret->next = head;
        ListNode* begin = ret, *curr = head, *next = head->next;
        
        while (curr != nullptr && next != nullptr) {
            curr->next = next->next;
            begin->next = next;
            next->next = curr;
            begin = curr;
            curr = curr->next;
            if (curr != nullptr) next = curr->next;
        }
        return ret->next;
        
    }
};
