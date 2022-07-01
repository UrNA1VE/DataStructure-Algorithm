// https://leetcode.com/problems/grid-game/

#define ll long long
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        ll res = 0, topsum = 0, bottomsum = 0;
        int n = grid[0].size();
        for (int i = 1; i < n; i++) {
            bottomsum += grid[0][i];
        }
        res = bottomsum;
        for (int i = 1; i < n; i++) {
            topsum += grid[1][i - 1];
            bottomsum -= grid[0][i];
            res = min(res, max(topsum, bottomsum));
        }
        return res;
        
    }
};
