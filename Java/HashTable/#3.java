// Given a string s, find the length of the longest substring without repeating characters.

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int res = 0, i = 0, j = 0, n = s.length();
        HashMap<Character, Integer> curr = new HashMap<Character, Integer>();
        while (j < n) {
            if (curr.containsKey(s.charAt(j)) && curr.get(s.charAt(j)) > 0) {
                curr.put(s.charAt(i), curr.get(s.charAt(i)) - 1);
                i++;
            }
            else {
                curr.put(s.charAt(j), 1);
                res = Math.max(res, j - i + 1);
                j++;
            }
        }
        return res;
 
    }
}
