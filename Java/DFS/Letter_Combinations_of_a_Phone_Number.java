// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
    public List<String> letterCombinations(String digits) {
        int n = digits.length();
        LinkedList<String> ret = new LinkedList<>();
        if (n == 0) return ret;
        ret.add("");
        String[] tmp = new String[]{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i = 0; i < n; i++) {
            int m = ret.size(), j = 0;
            int k = digits.charAt(i) - '0';
            while (j < m) {
                String curr = ret.remove();
                for (char c: tmp[k].toCharArray()) {
                    ret.add(curr + c);
                }
                j++;
            }
        }
        return ret;
    }
}
