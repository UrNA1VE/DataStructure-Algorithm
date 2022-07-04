// https://leetcode.com/problems/k-divisible-elements-subarrays/

class Trie {
    public Trie[] children = new Trie[201];
        
} 

class Solution {
    int ret;
    public void insert(Trie t, int[] nums, int i, int k, int p) {
        if (i == nums.length) return;
        int q = (nums[i]%p) == 0? 1: 0;
        if (k - q < 0) return;
        if (t.children[nums[i]] == null) {
            ret++;
            t.children[nums[i]] = new Trie();
        }
        insert(t.children[nums[i]], nums, i + 1, k - q, p);
        return;
    }

    public int countDistinct(int[] nums, int k, int p) {
        int n = nums.length;
        ret = 0;
        Trie root = new Trie();
        
        for (int i = 0; i < n; i++) {
            insert(root, nums, i, k, p);
        }
        return ret;
    }
}
