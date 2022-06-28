// https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool helper(unordered_map<char, int>& m1, unordered_map<char, int>& m2) {
        for (auto& [key, value]: m1) {
            if (m1[key] != m2[key]) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2) return false;
        unordered_map<char, int> m1, m2;
        for (char c: s1) {
            m1[c]++;
        }
        
        for (int i = 0; i < n1; i++) {
            m2[s2[i]]++;
        }
        if (helper(m1, m2)) return true;
        
        for (int i = n1; i < n2; i++) {
            m2[s2[i]]++;
            m2[s2[i - n1]]--;
            if (helper(m1, m2)) return true;

        }
        return false;
        
    }
};
