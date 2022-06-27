// https://leetcode.com/problems/length-of-last-word/

class Solution {
    public int lengthOfLastWord(String s) {
        int n = s.length() - 1;
        boolean flag = false;
        int res = 0;
        while (!flag && n >= 0) {
            if (s.charAt(n) == ' ') {
                n--;
            }
            else {
                flag = true;
                while (n >= 0 && s.charAt(n) != ' ') {
                    res++;
                    n--;
                }
            }
        }
        return res;
    }
}
