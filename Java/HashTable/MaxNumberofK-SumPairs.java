// https://leetcode.com/problems/max-number-of-k-sum-pairs/

class Solution {
    public int maxOperations(int[] nums, int k) {
        Map<Integer, Integer> m = new HashMap<>();
        for (int x: nums) {
            m.put(x, m.getOrDefault(x, 0) + 1);
        }
        
        int ret = 0;
        for (int key: m.keySet()) {
            int target = k - key;
            if (target == key) {
                int curr = m.get(key) / 2;
                m.put(key, m.get(key) % 2);
                ret += curr;
            }
            else if (m.containsKey(target)){
                int curr = Math.min(m.get(key), m.get(target));
                m.put(key, m.get(key) - curr);
                m.put(target, m.get(target) - curr);
                ret += curr;
            }
        }
        return ret;
                     
    }
}
