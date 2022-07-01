// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

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
    bool find(TreeNode* node, string& path, int target) {
        if (node->val == target) return true;
        if (node->left && find(node->left, path, target)) {
            path.push_back('L');
        }
        else if (node->right && find(node->right, path, target)) {
            path.push_back('R');
        }
        return !path.empty();
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string sp, dp;
        find(root, sp, startValue);
        find(root, dp, destValue);
        while (!sp.empty() && !dp.empty() && sp.back() == dp.back()) {
            sp.pop_back();
            dp.pop_back();
        }
        return string(sp.length(), 'U') + string(dp.rbegin(), dp.rend());
    }
};
