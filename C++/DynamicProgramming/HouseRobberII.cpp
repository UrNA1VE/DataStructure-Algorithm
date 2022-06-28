// https://leetcode.com/problems/house-robber-ii/submissions/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        vector<int> vector1(nums.begin(), nums.end() - 1);
        vector<int> vector2(nums.begin() + 1, nums.end());
        return max(dp_method(vector1), dp_method(vector2));
        
    }
private:
    int dp_method(const vector<int>& nums){
        int dp1 = 0, dp0 = 0, dp = 0;
        
        for (int i = 0; i < nums.size(); i ++){
            dp = max(dp0 + nums[i], dp1);
            dp0 = dp1;
            dp1 = dp;
        }
        return dp;
    }
};
