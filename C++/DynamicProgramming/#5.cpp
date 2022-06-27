// Given a string s, return the longest palindromic substring in s.
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), Max = 0;
        string ret;
        bool dp[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j]) {
                    if (j + 1 > i - 1 || dp[j + 1][i - 1]) {
                        dp[j][i] = true;
                        if (Max < i - j + 1) {
                            Max = i - j + 1;
                            ret = s.substr(j, Max);
                        }
                    }
                }
            }
        }
        return ret;
        
    }
};
