# Given a string s, find the length of the longest substring without repeating characters.

# Input: s = "abcabcbb"
# Output: 3
# Explanation: The answer is "abc", with the length of 3.
  
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        dic = {}
        res = 0
        start = 0
        for i in range(0, len(s)):
            if s[i] in dic:
                sums = dic[s[i]] + 1
                if start < sums:
                    start = sums
            dis = i - start + 1
            res = max(res, dis)
            dic[s[i]] = i
                    
        return res
