// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    bool dfs(TreeNode* curr, TreeNode* target, vector<TreeNode*>& path) {
        if (curr->val == target->val) {
            return true;
        }
        if (curr->left != nullptr) {
            path.push_back(curr->left);
            if (dfs(curr->left, target, path)) return true;
            path.pop_back();
        }
        if (curr->right != nullptr) {
            path.push_back(curr->right);
            if (dfs(curr->right, target, path)) return true;
            path.pop_back();
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathp;
        vector<TreeNode*> pathq;
        pathp.push_back(root);
        pathq.push_back(root);
        dfs(root, p, pathp);
        dfs(root, q, pathq);
        TreeNode* res = new TreeNode(-1);
        int i = 0, j = 0;
        int ni = pathp.size(), nj = pathq.size();
        while (i < ni && j < nj && pathp[i]->val == pathq[j]->val) {
            res = pathp[i];
            i++;
            j++;
            
        }
        return res;
        
    }
};
