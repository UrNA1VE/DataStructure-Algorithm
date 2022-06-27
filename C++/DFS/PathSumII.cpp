// https://leetcode.com/problems/path-sum-ii/

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(root, targetSum, res, cur);
        return res;
        
    }
private:
    void dfs(TreeNode* root, int target, vector<vector<int>>& res, vector<int>& cur){
        if (root == nullptr) return;
        else if (root->left == nullptr && root->right == nullptr){
            if (root->val == target){
                cur.push_back(root->val);
                res.push_back(cur);
                cur.pop_back();
                return;
            }
        }
        else {
            cur.push_back(root->val);
            dfs(root->left, target - root->val, res, cur);
            dfs(root->right, target - root->val, res, cur);
            cur.pop_back();
            return;
        }
    }
};
