// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sums = 0, l = 0, r = 0, res = INT_MAX, n = nums.size();
        while (r < n){
            sums += nums[r++];
            while (sums >= target){
                sums -= nums[l++];
                res = min(res, r - l + 1);

            }
        }
        return (res == INT_MAX? 0: res);
    }
};
