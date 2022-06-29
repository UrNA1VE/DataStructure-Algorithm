// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

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
    vector<int> sums;
    int maxProduct(TreeNode* root) {
        int root_sum = count_sum(root);
        int n = sums.size();
        long long res = 0, curr;
        for(int i = 0; i < n; i ++) {
            curr = (long long) (root_sum - sums[i]) * sums[i];
            res = (res > curr)? res: curr;
        }
        return res % (int) (1e9 + 7);

        
    }

    int count_sum(TreeNode* root) {
        int left = 0, right = 0, ans;
        if (root->left != nullptr) {
            left = count_sum(root->left);
        }
        if (root->right != nullptr) {
            right = count_sum(root->right);
        }
        ans = root->val + left + right;
        sums.push_back(ans);

        return ans;
    }
};
