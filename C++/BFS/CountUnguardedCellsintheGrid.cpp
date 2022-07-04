// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> map(m, vector<int>(n, 0));
        int occupied = guards.size() + walls.size();
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (vector<int>& x: guards) {
            map[x[0]][x[1]] = 2;
        }
        for (vector<int>& x: walls) {
            map[x[0]][x[1]] = 3;
        }
        
        for (vector<int>& g: guards) {
            int x = g[0], y = g[1];
            for (int k = 0; k < 4; k++) {
                int xx = x, yy = y;
                while (true) {
                    xx += dir[k][0];
                    yy += dir[k][1];
                    if (xx < 0 || xx >= m || yy < 0 || yy >= n || map[xx][yy] > 1) {
                        break;
                    }
                    if (map[xx][yy] != 1) {
                        map[xx][yy] = 1;
                        occupied++;
                    }
                }
            }
        }
        return m*n - occupied;
    }
};
