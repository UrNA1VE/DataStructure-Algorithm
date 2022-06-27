// https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
    public int longestValidParentheses(String s) {
        int curr = 0, n = s.length(), ret = 0;
        Deque<Integer> stack = new ArrayDeque<Integer>();
        int[] idx = new int[n];
        for (int i = 0; i < n; i++) {
            if (curr == 0 && s.charAt(i) == ')') {
                stack.push(i);
                idx[i] = i;
            }
            else if (curr > 0 && s.charAt(i) == ')') {
                curr--;
                stack.pop();
                idx[i] = stack.isEmpty()? -1: stack.peek();
            }
            else if (s.charAt(i) == '(') {
                curr++;
                idx[i] = i;
                stack.push(i);
            }
        }
        for (int i = 0; i < n; i++) {
            ret = Math.max(ret, i - idx[i]);
        }
        return ret;
    }
}
