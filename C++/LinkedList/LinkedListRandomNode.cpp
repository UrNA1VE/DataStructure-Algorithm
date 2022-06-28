// https://leetcode.com/problems/linked-list-random-node/

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
    int n = 0;
    ListNode *mHead;
    
    Solution(ListNode* head) {
        mHead = head;
        ListNode *p = head;
        while(p != nullptr) {
            n++;
            p = p->next;
        }
    }
    
    int getRandom() {
        ListNode *p = mHead;
        int target = rand() % n, curr = 0;
        while (curr != target) {
            curr++;
            p = p->next;
        }
        return p->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
