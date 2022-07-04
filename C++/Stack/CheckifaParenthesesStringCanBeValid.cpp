// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int nov = 0, fo = 0, fc = 0, n = s.length();
        if (n % 2) return false;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') nov++;
            else if (s[i] == '(') fo++;
            else fc++;
            if (nov + fo - fc < 0) return false;
        }
        
        nov = 0;
        fo = 0;
        fc = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '0') nov++;
            else if (s[i] == '(') fo++;
            else fc++;
            if (nov - fo + fc < 0) return false;
        }
        return true;
    }
};
