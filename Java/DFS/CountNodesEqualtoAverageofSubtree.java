// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ret = 0;
    
    public int[] dfs(TreeNode node) {
        int[] l = new int[2];
        int[] r = new int[2];
        if (node.left != null) {
            l = dfs(node.left);
        }
        if (node.right != null) {
            r = dfs(node.right);
        }
        
        int curr = node.val + l[0] + r[0];
        int cnt = 1 + l[1] + r[1];
        if (node.val == curr/cnt) {
            ret++;
        }
        return new int[]{curr, cnt};
        
    }
    
    public int averageOfSubtree(TreeNode root) {
        dfs(root);
        return ret;
    }
}
