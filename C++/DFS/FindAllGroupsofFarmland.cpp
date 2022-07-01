// https://leetcode.com/problems/find-all-groups-of-farmland/

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(),  n = land[0].size();
        vector<vector<bool>> visit (m, vector<bool> (n, false));
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visit[i][j] || land[i][j] == 0) continue;
                int left = j, up = i, right = j, down = i;
                while (right < n && land[down][right] == 1) {
                    visit[down][right] = true;
                    right++;
                }
                right--;
                while (down < m && land[down][right] == 1) {
                    visit[down][right] = true;
                    down++;
                }
                down--;
                for (int k = up; k <= down; k ++) {
                    for (int l = left; l <= right; l ++) {
                        visit[k][l] = true;
                    }
                } 
                res.push_back(vector<int> {up, left, down, right});
                
            }
        }
        return res;
        
    }
};
