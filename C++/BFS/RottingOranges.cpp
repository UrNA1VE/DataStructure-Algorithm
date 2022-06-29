// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), sum = 0, curr = 0, round = 0;
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visit(m, vector<bool> (n, false));
        queue<pair<int, int>> q;
        queue<pair<int, int>> next_q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    visit[i][j] = false;
                    next_q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    sum++;
                }
            }
        }
        
        while (!next_q.empty() && curr < sum) {
            swap(next_q, q);
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int xx = x + dir[i][0], yy = y + dir[i][1];
                    if (xx >= 0 && xx < m && yy >= 0 && yy < n && grid[xx][yy] == 1 && visit[xx][yy] == false) {
                        visit[xx][yy] = true;
                        next_q.push({xx, yy});
                        curr++;
                    }    
                }
            }
            round++;
        }
        
        if (curr < sum && next_q.empty()) return -1;
        return round;
    }
};
