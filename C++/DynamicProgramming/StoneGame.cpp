// https://leetcode.com/problems/stone-game/

class Solution {
public:
    int dp[501][501] = {};
    int helper(bool alex, int left, int right, vector<int>& piles) {
        if (left > right) return 0;
        if (left == right) return piles[left];
        
        if (dp[left][right] != -1) return dp[left][right];
        
        if (alex) {
            dp[left][right] = max(piles[left] + helper(!alex, left + 1, right, piles), piles[right] + helper(!alex, left, right - 1, piles));
        }
        else {
            dp[left][right] = min(-piles[left] + helper(!alex, left + 1, right, piles), -piles[right] + helper(!alex, left, right - 1, piles));
        }
        return dp[left][right];
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        return helper(true, 0, n - 1, piles) > 0;
        
    }
};
