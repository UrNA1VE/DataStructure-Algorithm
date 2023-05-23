// https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/description/

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.length(), i = 0, ret = 1;
        while (i < n) {
            int j = i + 1;
            while (true) {
                if (j == n || s[j] != s[j - 1] + 1) {
                    ret = max(ret, j - i);
                    break;
                }
                else j++;
            }
            i = j;
        }
        return ret;
    }
};
