// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

#define ll long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), res = 0, sum = 0;
        vector<unordered_map<ll, int>> dp(n);
        ll delta = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                delta = (ll) nums[i] - (ll) nums[j];
                sum = 0;
                if (dp[j].find(delta) != dp[j].end()) sum = dp[j][delta];
                dp[i][delta] += sum + 1;
                res += sum;
            }
        }
        return res;

        
    }
};
