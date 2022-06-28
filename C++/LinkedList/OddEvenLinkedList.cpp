// https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) 
            return head;
        ListNode* p1 = head->next;
        ListNode* p2 = head->next->next;
        ListNode* p3 = head->next;
        ListNode* p4 = head;
        
        while (true) {
            p4->next = p2;
            p1->next = p2->next;
            p4 = p2;
            p4->next = p3;
            if (p1->next == nullptr || p1->next->next == nullptr) 
                return head;
            p1 = p1->next;
            p2 = p1->next;
        }
        return head;
    }
};
