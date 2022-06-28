// https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), target = 0;
        for (int num: nums) {
            target += num;
        }
        if (target % 2) return false;
        target /= 2;
        
        vector<bool> pre(target + 1, false);
        vector<bool> curr(target + 1, false);
        for (int i = 0; i < n; i++) {
            pre[0] = true;
            for (int j = 0; j < target + 1; j++) {
                if (j < nums[i]) {
                    curr[j] = pre[j];
                }
                else {
                    curr[j] = pre[j] | pre[j - nums[i]];
                }       
            }
            swap(pre, curr);  
        }
        return pre[target];
        
    }
};
