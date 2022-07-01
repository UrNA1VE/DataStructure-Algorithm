// https://leetcode.com/problems/maximum-compatibility-score-sum/

class Solution {
public:
    int helper(vector<int>& s, vector<int>& m) {
        int ret = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == m[i]) ret++;
        }
        return ret;
    }
    
    int maxC(vector<vector<int>>& s, vector<vector<int>>& m, int i, int mask) {
        if (i == s.size()) return 0;
        int ret = 0;
        
        for (int j = 0; j < s.size(); j++) {
            if ((1 & (mask>>j)) == 0) {
                int new_mask = (1 << j) | mask;
                ret = max(ret, helper(s[i], m[j]) + maxC(s, m, i + 1, new_mask));
            }
        }
        return ret;
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        return maxC(students, mentors, 0, 0);
    }
};
