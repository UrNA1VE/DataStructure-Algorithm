// https://leetcode.com/problems/shifting-letters/

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        shifts[n - 1] %= 26;
        for (int i = n - 2; i >= 0; i--) {
            shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] + shifts[i] > 'z') s[i] += (shifts[i] - 'z' + 'a' - 1);
            else s[i] += shifts[i];
        }
        return s;
        
        
        
    }
};
