// https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> ret;
    
    void helper(vector<int>& nums, vector<int>& curr, int i) {
        if (i == nums.size()) {
            ret.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        helper(nums, curr, i + 1);
        curr.pop_back();
        helper(nums, curr, i + 1);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        helper(nums, curr, 0);
        return ret;
    }
};
