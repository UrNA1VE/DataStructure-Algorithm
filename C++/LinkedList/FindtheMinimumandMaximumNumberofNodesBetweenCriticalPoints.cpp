// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *p = head, *pre = head, *next = head;
        p = p->next;
        next = next->next->next;
        vector<int> res(2, -1);
        int prev = -1, first = -1, count = 1;
        
        while (next != nullptr) {
            if ((p->val > next->val && p->val > pre->val) || (p->val < next->val && p->val < pre->val)) {
                if (prev == -1) {
                    prev = count;
                    first = count;
                }
                else {
                    if (res[0] == -1) {
                        res[0] = count - prev;
                        res[1] = count - prev;
                    }
                    else {
                        res[0] = min(res[0], count - prev);
                        res[1] = count - first;
                    }
                    prev = count;
                }

            }
            count++;
            p = p->next;
            next = next->next;
            pre = pre->next;
        }
        return res;
        
        
        
    }
};
