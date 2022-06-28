// https://leetcode.com/problems/insert-into-a-binary-search-tree/

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
    void helper(TreeNode* node, int val) {
        if (node->val > val) {
            if (node->left != nullptr) {
                helper(node->left, val);
            }
            else {
                node->left = new TreeNode(val);
                return;
            }
        }
        else {
            if (node->right != nullptr) {
                helper(node->right, val);
            }
            else {
                node->right = new TreeNode(val);
                return;
            }
        }
        return;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        helper(root, val);
        return root;
        
        
    }
};
