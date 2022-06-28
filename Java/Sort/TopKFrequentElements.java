// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int n = nums.length;
        List<Integer>[] buckets = new ArrayList[n + 1];
        Map<Integer, Integer> counts = new HashMap<Integer, Integer>();
        
        for (int x: nums) {
            counts.put(x, counts.getOrDefault(x, 0) + 1);
        }
        
        for (int key: counts.keySet()) {
            int val = counts.get(key);
            if (buckets[val] == null) {
                buckets[val] = new ArrayList();
            }
            buckets[val].add(key);
        }
        
        int[] ret = new int[k];
        int j = 0;
        for (int i = n; i >= 0 && j < k; i--) {
            if (buckets[i] != null) {
                for (int x: buckets[i]) {
                    ret[j] = x;
                    j++;
                }
            }
        }
        
        return(ret);
    }
}
