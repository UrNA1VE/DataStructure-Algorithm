// https://leetcode.com/problems/minimum-operations-to-halve-array-sum/

class Solution {
    public int halveArray(int[] nums) {
        double all = 0, k = 0;
        int ret = 0;
        PriorityQueue<Double> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int x: nums) {
            all += x;
            pq.offer((double) x);
        }
        
        while (all - k > all/2) {
            Double x = pq.poll();
            pq.offer(x/2);
            k += x/2;
            ret += 1;
        }
        return ret;
        
    }
}
