// https://leetcode.com/problems/summary-ranges/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int n = nums.size();
        for (int i = 0, j = 0; i < n; i = ++j) {
            while (j < n - 1 && nums[j + 1] == nums[j] + 1) {
                j++;
            }
            if (i < n) ret.push_back(to_string(nums[i]) + (i < j? "->" + to_string(nums[j]) : ""));
        }

        return ret;
        
    }
};
