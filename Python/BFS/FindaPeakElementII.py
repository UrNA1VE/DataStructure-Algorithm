# https://leetcode.com/problems/find-a-peak-element-ii/

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int yend = mat[0].size(), xend = mat.size(), x = 0, y = 0;
        auto func = [mat, xend, yend](int x, int y) -> int { return (0 <= x && x < xend && 0 <= y && y < yend)? mat[x][y]: -1;};
        int xx, yy, height;
        int next_x, next_y;
        while (true) {
            int max_height = func(x, y);
            next_x = x;
            next_y = y;
            for (int i = 0; i < 4; i ++) {
                xx = x + dir[i][0];
                yy = y + dir[i][1];
                height = func(xx, yy);
                if (height > max_height) {
                    next_x = xx;
                    next_y = yy;
                    max_height = height;
                }
                
            }
            if (next_x == x && next_y == y) {
                return {x, y};
            }
            x = next_x;
            y = next_y;
        }
    }
};
