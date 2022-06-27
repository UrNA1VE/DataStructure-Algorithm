// Given a string s, find the length of the longest substring without repeating characters.

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> visit;
        int n = s.length(), i = 0, j = 0, ret = 0;
        while (j < n) {
            if (visit.count(s[j]) == 0) {
                visit.insert(s[j++]);
                ret = max(ret, j - i);
            }
            else {
                visit.erase(s[i++]);
            }
        }
        return ret;
        
        
    }
};
