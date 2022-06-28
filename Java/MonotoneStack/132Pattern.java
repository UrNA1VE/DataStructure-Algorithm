// https://leetcode.com/problems/132-pattern/

class Solution {
    public boolean find132pattern(int[] nums) {
        int numk = Integer.MIN_VALUE, n = nums.length;
        Stack<Integer> s = new Stack<>();
        for (int i = n - 1; i >= 0; i--) {
            int x = nums[i];
            if (x < numk) {
                return true;
            }
            while (!s.empty() && s.peek() < x) {
                numk = s.pop();
            }
            s.push(x);
        }
        return false;
        
    }
}
