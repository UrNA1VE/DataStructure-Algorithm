// https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time/

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; i ++) {
            for (int j = n; j >= 0; j --) {
                dp[j] += dist[i];
                if (i < n - 1) 
                    dp[j] = (dp[j] + speed - 1) / speed * speed;
                if (j > 0) 
                    dp[j] = min(dp[j], dp[j - 1] + dist[i]);
            }
        }
        
        for (int i = 0; i <= n; i ++) {
            if (dp[i] <= (long) speed * hoursBefore)
                return i;
        }
        return -1;
    }
};
