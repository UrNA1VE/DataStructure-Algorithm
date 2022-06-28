// https://leetcode.com/problems/island-perimeter/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int visit[m][n];
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < m && q.empty(); i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    break;
                }
            }
        }
        int x, y, count = 0, xx, yy, res = 0;
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            if (visit[x][y] == 1) continue;
            visit[x][y] = 1;
            count = 0;
            for (int i = 0; i < 4; i++) {
                xx = x + dir[i][0];
                yy = y + dir[i][1];
                if (xx < m && xx >= 0 && yy < n && yy >= 0 && grid[xx][yy] == 1) {
                    count++;
                    q.push({xx, yy});
                }
                
            }
            
            res += (4 - count);
            
        }
        return res;
        
    }
};
