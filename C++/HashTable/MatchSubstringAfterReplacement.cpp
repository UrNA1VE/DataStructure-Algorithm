// https://leetcode.com/problems/match-substring-after-replacement/

class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<char, unordered_set<char>> helper;
        for (vector<char>& m: mappings) {
            helper[m[0]].insert(m[1]);
        }
        int m = s.length(), n = sub.length();
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            for (j = 0; j < n; j++) {
                if (s[i + j] != sub[j] && helper[sub[j]].count(s[i + j]) == 0) break;
                
            }
            if (j == n) return true;
        }
        
        return false;
        
    }
};
