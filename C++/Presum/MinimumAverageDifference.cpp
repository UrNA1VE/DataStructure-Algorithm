// https://leetcode.com/problems/minimum-average-difference/

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for (int x: nums) {
            total += x;
        }
        
        int ret = -1, m = INT_MAX;
        long long all = total, sub_total = 0;
        
        for (int i = 0; i < n - 1; i++) {
            sub_total += nums[i];
            total -= nums[i];
            int curr = (int) abs(sub_total / (i + 1) - total / (n - 1 - i));
            if (curr < m) {
                m = curr;
                ret = i;
            }
        }
        if (all / n < m) return n - 1;
        return ret;
        
        
        
        
    }
};
