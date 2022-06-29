// https://leetcode.com/problems/stone-game-ii/

class Solution {
public:
    int helper(vector<int>& piles, vector<vector<int>>& dp, vector<int>& suffix, int index, int m) {
        if (index >= piles.size()) return 0;
        if (index + 2 * m >= piles.size()) return suffix[index];
        if (dp[index][m] != -1) return dp[index][m];
        int t = INT_MAX;
        for (int k = index + 1; k <= index + 2 * m; k++) {
            t = min(t, helper(piles, dp, suffix, k, max(m, k - index)));
        }
        dp[index][m] = suffix[index] - t;
        return dp[index][m];
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector <int> suffix(n, 0);
        vector < vector <int> > dp(n+1, vector <int> (n+1, -1));
        suffix[n-1] = piles[n-1];
        for (int i = n - 2; i >-1; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        return helper(piles, dp, suffix, 0, 1);
    }
};
