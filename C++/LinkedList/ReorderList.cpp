// https://leetcode.com/problems/reorder-list/

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
    void reorderList(ListNode* head) {
        std::vector<ListNode*> list;
        for (; head; head = head->next)
            list.push_back(head);
        for (int i = 0; i < list.size() / 2; ++i) {
            list[i]->next = list[list.size() - i - 1];
            list[list.size() - i - 1]->next = list[i + 1];
        }
        list[list.size() / 2]->next = nullptr;
    }
};
