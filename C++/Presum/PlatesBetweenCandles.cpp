// https://leetcode.com/problems/plates-between-candles/

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length(), m = queries.size();
        vector<int> LeftBound(n), RightBound(n), PreSum(n), res(m);
        int left = -1, right = n, curr = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '|') left = i;
            LeftBound[i] = left;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '|') right = i;
            RightBound[i] = right;
        }
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') curr++;
            PreSum[i] = curr;
        }
        
        for (int i = 0; i < m; i++) {
            left = RightBound[queries[i][0]];
            right = LeftBound[queries[i][1]];
            if (left >= right) {
                res[i] = 0;
            }
            else {
                res[i] = PreSum[right] - PreSum[left];
            }
        }
        return res;
        
    }
};
