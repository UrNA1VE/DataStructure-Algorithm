// https://leetcode.com/problems/total-appeal-of-a-string/

class Solution {
    public long appealSum(String s) {
        long res = 0, cur = 0, prev[] = new long[26];
        for (int i = 0; i < s.length(); ++i) {
            cur += i + 1 - prev[s.charAt(i) - 'a'];
            prev[s.charAt(i) - 'a'] = i + 1;
            res += cur;
        }    
        return res;
    }
}
