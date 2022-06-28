// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    bool helper(unordered_map<char, int>& curr, unordered_map<char, int>& target) {
        for (auto x: target) {
            if (curr[x.first] != x.second) return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), m = p.length();
        vector<int> ret;
        if (m > n) return ret;
        unordered_map<char, int> target, curr;
        
        for (char c: p) {
            target[c]++;
        }
        
        for (int i = 0; i < m; i++) {
            curr[s[i]]++;
        }
        if (helper(curr, target)) ret.push_back(0);
        for (int i = 1; i <= n - m; i++) {
            curr[s[i - 1]]--;
            curr[s[i + m - 1]]++;
            if (helper(curr, target)) ret.push_back(i);
        }
        return ret;
    }
};
