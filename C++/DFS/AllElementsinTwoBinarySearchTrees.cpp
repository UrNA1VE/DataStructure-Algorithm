// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

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
    vector<int> v1, v2;
    
    void dfs(TreeNode* root, vector<int>& v) {
        if (root->left) {
            dfs(root->left, v);
        }
        v.push_back(root->val);
        if (root->right) {
            dfs(root->right, v);
        }
        
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if (root1 != nullptr) dfs(root1, v1);
        if (root2 != nullptr) dfs(root2, v2);
        int n1 = v1.size(), n2 = v2.size(), i = 0, j = 0;
        vector<int> ret;
        while (i < n1 && j < n2) {
            if (v1[i] < v2[j]) {
                ret.push_back(v1[i++]);
            }
            else {
                ret.push_back(v2[j++]);
            }
        }
        if (i < n1) {
            while (i < n1) {
                ret.push_back(v1[i++]);
            }
        }
        if (j < n2) {
            while (j < n2) {
                ret.push_back(v2[j++]);
            }
        }
        return ret;
    }
};
