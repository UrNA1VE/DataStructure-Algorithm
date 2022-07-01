// https://leetcode.com/problems/maximum-earnings-from-taxi/

#define ll long long
class Solution {
public:

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(), [](vector<int>& a, vector<int>& b){
            return a[1] > b[1];
        });
        vector<ll> dp(n + 1, 0);
        int j = 0, m = rides.size();
        ll res = 0;
        for (int i = n; i >= 1; i--) {
            res = max(res, dp[i]);
            while (j < m && rides[j][1] == i) {
                dp[rides[j][0]] = max(dp[rides[j][0]], res + rides[j][1] - rides[j][0] + rides[j][2]);
                j++;
            }
        }
        return res;
    }
};
