// https://leetcode.com/problems/binary-tree-paths/

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
    vector<string> res;
    
    void dfs(TreeNode* node, string& curr) {
        int n = curr.length();
        if (node->left == nullptr && node->right == nullptr) {
            res.push_back(curr);
            return;
        }
        if (node->left != nullptr) {
            curr += "->";
            curr += to_string(node->left->val);
            dfs(node->left, curr);
            curr = curr.substr(0, n);
        }
        if (node->right != nullptr) {
            curr += "->";
            curr += to_string(node->right->val);
            dfs(node->right, curr);
            curr = curr.substr(0, n);
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return res;
        string curr = to_string(root->val);
        dfs(root, curr);
        return res;
        
        
    }
};
