// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int res = 0;
    
    void dfs(TreeNode* node, int curr) {
        if (node->left == nullptr && node->right == nullptr) {
            res += curr;
            return;
        }
        if (node->left != nullptr) {
            dfs(node->left, 10* curr + node->left->val);
        }
        if (node->right != nullptr) {
            dfs(node->right, 10* curr + node->right->val);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        dfs(root, root->val);
        return res;
        
    }
};
