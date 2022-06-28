// https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size(), x;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            x = abs(nums[i]);
            if (nums[x - 1] < 0) res.push_back(x);
            else nums[x - 1] = -nums[x - 1];
        }
        return res;
        
    }
};
