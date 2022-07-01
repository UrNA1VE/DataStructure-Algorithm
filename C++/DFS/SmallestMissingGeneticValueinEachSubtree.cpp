// https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/

class Solution {
public:
    unordered_set<int> visit;
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        vector<int> res(n, 1);
        
        auto it = find(nums.begin(), nums.end(), 1);
        if (it == nums.cend()) return res;
        
        vector<vector<int>> children(n, vector<int> ());
        for (int i = 1; i < n; i++) {
            children[parents[i]].push_back(i);
        }
        int miss = 1, i = it - nums.begin();
        while (i > -1) {
            dfs(children, nums, i);
            while (visit.find(miss) != visit.cend()) {
                miss++;
            }
            res[i] = miss;
            i = parents[i];  
        }
        
        return res;
    }
    
    void dfs(vector<vector<int>>& children, vector<int>& nums, int i) {
        if (visit.find(nums[i]) != visit.cend()) return;
        for (int c: children[i]) {
            dfs(children, nums, c);
        }
        visit.insert(nums[i]);
        return;
    }
};

