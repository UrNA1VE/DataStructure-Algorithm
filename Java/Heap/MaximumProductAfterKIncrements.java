// https://leetcode.com/problems/maximum-product-after-k-increments/

class Solution {
    public int maximumProduct(int[] nums, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for (int x: nums) {
            pq.add((long) x);
        }
        
        while (k > 0) {
            k--;
            long x = pq.poll();
            x++;
            pq.add(x);
        }
        
        long ret = 1, mod = 1000000007;
        while (pq.size() > 0) {
            ret = (ret * pq.poll()) % mod;
        }
        return (int)ret;
        
    }
}
