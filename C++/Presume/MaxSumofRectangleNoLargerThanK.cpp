// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

class Solution {
public:
    int res = INT_MIN;
    
    void helper(vector<int>& nums, int k) {
        int sum = 0;
        set<int> sortedSum;
        
        sortedSum.insert(0);
        for (int num: nums) {
            sum += num;
            auto it = sortedSum.lower_bound(sum - k);
            if (it != sortedSum.end()) {
                res = max(res, sum - *it);
            }
            sortedSum.insert(sum);
        }
    }
    
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rowsum (n, 0);
        for (int i = 0; i < m; i++) {
            fill(rowsum.begin(), rowsum.end(), 0);
            for (int row = i; row < m; row ++) {
                for (int col = 0; col < n; col ++) {
                    rowsum[col] += matrix[row][col];
                }
                helper(rowsum, k);
                if (res == k) return res;
                
            }
        }
        return res;
        
    }
};
