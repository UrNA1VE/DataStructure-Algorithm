// https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ret;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if ((i - 1 < 0 || (nums[i - 1] != x - 1 && nums[i - 1] != x)) && (i + 1 >= n || (nums[i + 1] != x + 1 && nums[i + 1] != x))) {
                ret.push_back(x);
            }
        }
        return ret;
        
    }
};
