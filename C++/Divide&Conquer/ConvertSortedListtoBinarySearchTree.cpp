// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return NULL;
        if (head->next == nullptr) return new TreeNode(head->val);
        ListNode* mid = NULL, *pre = NULL;
        mid = findmid(head, &pre);
        TreeNode* root = new TreeNode(mid->val);
        if (mid != nullptr){
            if (pre->next != nullptr) pre->next = NULL;
            root->left = sortedListToBST(head);
            root->right = sortedListToBST(mid->next);
        }
        return root;
        
        
    }
    
private:
    ListNode* findmid(ListNode*head, ListNode** pre){
        ListNode* slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr){
            *pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
