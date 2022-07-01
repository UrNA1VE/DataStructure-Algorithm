// https://leetcode.com/problems/last-day-where-you-can-still-cross/

class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int right = cells.size(), left = 1, mid = 0, res = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (helper(row, col, mid, cells)) {
                left = mid + 1;
                res = mid;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
        
    }
    
    vector<vector<int>> make_grid(int row, int col, int day, vector<vector<int>>& cells) {
        vector<vector<int>> grid (row, vector<int> (col, 0));
        for (int i = 0; i < day; i ++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }
        
        return grid;
    }
    
    bool helper(int row, int col, int day, vector<vector<int>>& cells) {
        
        vector<vector<int>> grid = make_grid(row, col, day, cells);
        queue<pair<int, int>> process;
        int xx, yy, x, y;
        for (int start = 0; start < col; start++) {
             
            if (grid[0][start] == 0) {
                process.push({0, start});
                grid[0][start] = 1;

            }
        }
        while (!process.empty()) {
            
            auto [x, y] = process.front();
            process.pop();
            
            if (x == row - 1) return true;
            for (int i = 0; i < 4; i ++) {
                xx = x + dir[i][0];
                yy = y + dir[i][1];
                if (xx >= 0 && xx < row && yy >= 0 && yy < col && grid[xx][yy] == 0) {
                    grid[xx][yy] = 1;
                    process.push({xx, yy});
                }
            }
            
        }
        return false;
    }
};
