// https://leetcode.com/problems/balanced-binary-tree/


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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr){
            return true;
        }
        int left, right;
        left = helper(root->left);
        right = helper(root->right);
        return (abs(left - right) <= 1) && isBalanced(root->left) && isBalanced(root->right);
        
        
    }
private:
    int helper(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        return max(helper(root->left), helper(root->right)) + 1;
    }
};
