// https://leetcode.com/problems/insertion-sort-list/

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
    ListNode* insertionSortList(ListNode* head) {
        if (head->next == nullptr) return head;
        ListNode* p = head->next, *newHead = head, *nex = p;
        newHead->next = nullptr;
        while (p != nullptr) {
            nex = nex->next;
            if (p->val <= newHead->val) {
                p->next = newHead;
                newHead = p;
            } 
            else {
                ListNode* curr = newHead, *newNext = curr->next;
                while (newNext != nullptr && newNext->val < p->val) {
                    newNext = newNext->next;
                    curr = curr->next;
                }
                if (newNext == nullptr) {
                    curr->next = p;
                    p->next = nullptr;
                }
                else {
                    curr->next = p;
                    p->next = newNext;
                }
            }
            p = nex;
        }
        return newHead;
        
    }
};
