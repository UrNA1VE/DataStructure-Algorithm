// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> ret;
    void dfs(vector<int>& cans, vector<int>& nums, int idx, int n, int target, int curr) {
        if (curr == target) ret.push_back(nums);
        for (int i = idx; i < n; i++) {
            if (cans[i] + curr > target) break;
            nums.push_back(cans[i]);
            dfs(cans, nums, i, n, target, curr + cans[i]);
            nums.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> nums;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, nums, 0, candidates.size(), target, 0);
        return ret;
    }
};
