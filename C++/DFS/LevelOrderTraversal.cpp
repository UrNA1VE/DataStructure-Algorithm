// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> process;
        vector<vector<int>> res;
        if (root == nullptr) return res;
        process.push(root);
        while (!process.empty()){
            queue<TreeNode*> curr;
            vector<int> sub;
            while (!process.empty()){
                TreeNode* node = process.front();
                process.pop();
                if (node->left) curr.push(node->left);
                if (node->right) curr.push(node->right);
                sub.push_back(node->val);
                
            }
            swap(process, curr);
            res.push_back(sub);
        }
        return res;
        
        
    }
};
