// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* p = head;
        int n = 0;
        while (p != nullptr) {
            p = p->next;
            n++;
        }
        
        if (n == 1) return nullptr;
        
        int target = n / 2, count = 0;
        p = head;
        while (count != target - 1) {
            p = p->next;
            count++;
        }
        p->next = p->next->next;
        return head;
        
        
    }
};
