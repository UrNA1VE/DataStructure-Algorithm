// https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    int helper(vector<int>& heights) {
        int n = heights.size(), pre, height, res = 0, l, h;
        stack<int> s;
        for (int i = 0; i <= n; i++) {
            height = i < n? heights[i]: 0;
            while (!s.empty() && heights[s.top()] >= height) {
                pre = s.top();
                s.pop();
                h = heights[pre];
                l = i - 1 - (!s.empty()? s.top(): -1);
                res = max(res, l * h);
            }
            s.push(i);
        }
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<int> row(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    row[j] += 1;
                }
                else {
                    row[j] = 0;
                }
            }
            res = max(res, helper(row));
        }
        return res; 
    }
};
