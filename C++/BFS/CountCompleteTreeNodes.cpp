// https://leetcode.com/problems/count-complete-tree-nodes/

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
    int countNodes(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        int res = 0;
        queue<TreeNode*> process;
        process.push(root);
        while (!process.empty()){
            TreeNode* node = process.front();
            res += 1; 
            process.pop();
            if (node->left) process.push(node->left);
            if (node->right) process.push(node->right);
        }
        return res;
    }
};
