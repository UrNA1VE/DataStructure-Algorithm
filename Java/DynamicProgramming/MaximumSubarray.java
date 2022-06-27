// https://leetcode.com/problems/maximum-subarray/


class Solution {
    public int maxSubArray(int[] nums) {
        int dp = nums[0], res = dp;
        for (int i = 1; i < nums.length; i++) {
            if (dp > 0) {
                dp += nums[i]; 
            }
            else {
                dp = nums[i];
            }
            res = Math.max(dp, res);
        }
        return res;
        
    }
}
