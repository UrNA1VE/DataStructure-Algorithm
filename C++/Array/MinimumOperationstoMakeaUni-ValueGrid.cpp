// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size(), all = m * n;
        vector<int> arr;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr.emplace_back(grid[i][j]);
            }
        }
        sort(arr.begin(), arr.end());
        int target = arr[all/2], res = 0;
        
        for (int i = 0; i < all; i++) {
            if (abs(arr[i] - target) % x != 0) {
                return -1;
            }
            else res += abs(arr[i] - target) / x; 
        }
        return res;
    }
};
