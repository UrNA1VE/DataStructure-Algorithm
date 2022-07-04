// https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int cnt = 0, pow = 1, curr = 0;
        for (int i = s.length() - 1; i >= 0 && pow + curr <= k; i--) {
            if (s[i] == '1') {
                cnt++;
                curr += pow;
            }
            pow <<= 1;
        }
        return count(s.begin(), s.end(), '0') + cnt;
    }
};
