// https://leetcode.com/problems/count-subarrays-with-score-less-than-k/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int l = 0, r = 0;
        long long ret = 0, curr_sum = nums[0];;
        while (r < n) {
            long long temp = (long long) curr_sum * (r - l + 1);
            if (temp >= k) {
                curr_sum -= nums[l++];
            }
            else {
                ret += (long long) r - l + 1;
                if (r == n - 1) return ret;
                curr_sum += nums[++r];
            }
        }
        return ret;
        
    }
};
