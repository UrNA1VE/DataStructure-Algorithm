// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/

class Solution {
public:
    int minFlips(string s) {
        int n = s.length(), n2 = 2*n;
        string s1, s2;
        s += s;
        
        for (int i = 0; i < n2; i ++) {
            s1 += i % 2 ? '0' : '1';
            s2 += i % 2 ? '1' : '0';
        }
        
        int res = INT_MAX, res1 = 0, res2 = 0;
        
        for (int i = 0; i < n2; i ++) {
            if (s1[i] != s[i]) res1 ++;
            if (s2[i] != s[i]) res2 ++;
            
            if (i >= n - 1) {
                if (i >= n) {
                    if (s1[i - n] != s[i - n]) res1--;
                    if (s2[i - n] != s[i - n]) res2--;
                }
                res = min({res1, res2, res});
            }
        }
        return res;
        
    }
};
