// https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        else if (root->left == nullptr && root->right == nullptr) return 1;
        else if (root->left == nullptr) return minDepth(root->right) + 1;
        else if (root->right == nullptr) return minDepth(root->left) + 1;
        else return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
// private:
//     int helper(TreeNode* root){
//         if (root == nullptr){
//             return 0;
//         }
//         return min(helper(root->left), helper(root->right)) + 1;
//     }
};
