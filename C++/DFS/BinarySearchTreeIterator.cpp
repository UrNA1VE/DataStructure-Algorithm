// https://leetcode.com/problems/binary-search-tree-iterator/

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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        i = 0;
        dfs(root);
    }
    
    int next() {
        return stack[i++];
        
    }
    
    bool hasNext() {
        return i <= stack.size() - 1;
    }
private:
    vector<int> stack;
    int i;
    void dfs(TreeNode* root){
        if (root == nullptr){
            return;
        }
        if (root->left != nullptr) dfs(root->left);
        stack.push_back(root->val);
        if (root->right != nullptr) dfs(root->right);
        return;

    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
