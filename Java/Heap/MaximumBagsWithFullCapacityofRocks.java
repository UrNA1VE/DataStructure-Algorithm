// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/

class Solution {
    public int maximumBags(int[] capacity, int[] rocks, int additionalRocks) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int ret = 0, n = capacity.length;
        for (int i = 0; i < n; i++) {
            if (capacity[i] - rocks[i] == 0) {
                ret++;
            }
            else {
                pq.add(capacity[i] - rocks[i]);
            }
        }
        
        while (!pq.isEmpty() && additionalRocks > 0) {
            int curr = pq.poll();
            int x = Math.min(curr, additionalRocks);
            curr -= x;
            additionalRocks -= x;
            if (curr == 0) {
                ret++;
            }
            else {
               return ret; 
            }
        }
        return ret;
    }
}
