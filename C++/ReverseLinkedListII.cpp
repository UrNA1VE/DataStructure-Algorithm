// https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ret = new ListNode(-1);
        ret->next = head;
        if (left == right) return head;
        vector<ListNode*> arr;
        int idx = 0;
        ListNode* p = ret, *pre = nullptr, *last = nullptr;
        
        while (p != nullptr) {
            if (idx == left - 1) {
                pre = p;
            }
            else if (idx >= left && idx <= right) {
                arr.push_back(p);
            }
            else if (idx > right) {
                last = p;
                break;
            }
            idx++;
            p = p->next;
        }
        for (int i = right - left; i >= 0; i--) {
            pre->next = arr[i];
            pre = pre->next;
        }
        pre->next = last;
        return ret->next;     
    }
};
