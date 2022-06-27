// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return helper(inorder, postorder, 0, n -1 , 0, n - 1);
        
    }
private:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inleft, int inright, int postleft, int postright){
        if (inleft > inright){
            return nullptr;
        }
        int rootval = postorder[postright], i = inleft;
        while (i <= inright && inorder[i] != rootval){
            i++;
        }
        TreeNode* left = helper(inorder, postorder, inleft, i - 1, postleft, postleft + i - inleft - 1);
        TreeNode* right = helper(inorder, postorder, i + 1, inright, postleft + i - inleft, postright - 1);
        return new TreeNode(rootval, left, right);
        
        
    }
};
