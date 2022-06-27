// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int up = 0, down = m - 1, left = 0, right = n - 1;
        vector<int> res;
        while (left <= right && up <= down) {
            if (left == right) {
                for (int i = up; i <= down; i++) {
                    res.push_back(matrix[i][left]);
                }
                break;
            }
            if (up == down) {
                for (int i = left; i <= right; i++) {
                    res.push_back(matrix[up][i]);
                }
                break;
            }
            for (int i = left; i < right; i++) {
                res.push_back(matrix[up][i]);
            }
            for (int i = up; i < down; i++) {
                res.push_back(matrix[i][right]);
            }
            for (int i = right; i > left; i--) {
                res.push_back(matrix[down][i]);
            }
            for (int i = down; i > up; i--) {
                res.push_back(matrix[i][left]);
            }
            down--;
            up++;
            left++;
            right--;
        }
        return res;
        
    }
};
