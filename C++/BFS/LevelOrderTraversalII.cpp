// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)   return {};
        vector<vector<int>> result;
        vector<int> temp;
        TreeNode* current = root;
        queue<TreeNode*> q;
        int n = 1;
        q.push(root);
        while(!q.empty()){
            n = q.size();
            temp.clear();
            for(int i=0;i<n;i++){
                current = q.front();    q.pop();
                if(current->left)   
                    q.push(current->left);
                if(current->right)  
                    q.push(current->right);
                temp.push_back(current->val);
            }
            result.push_back(temp);
        }
        return vector(result.rbegin(),result.rend());
    }
};
