# Given a string s, return the longest palindromic substring in s.
# Input: s = "babad"
# Output: "bab"
# Explanation: "aba" is also a valid answer.

class Solution:
    def longestPalindrome(self, s: str) -> str:
        size = len(s)
        dp = [[False] * size for i in range(size)]
        res = s[0:1]
        
        def helper(i, j):
            nonlocal res
            if s[i] == s[j] and (i - j < 2 or dp[j + 1][i - 1]):
                dp[j][i] = True
                if len(res) < i - j + 1:
                    res = s[j: i + 1]

            return

        for i in range(size):
            dp[i][i] = True
        for i in range(size):
            for j in range(i - 1, -1, -1):
                helper(i, j)
        return res
        
