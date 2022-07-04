// https://leetcode.com/problems/find-players-with-zero-or-one-losses/

class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        Map<Integer, Integer> counts = new TreeMap<Integer, Integer>();
        for (int[] m: matches) {
            counts.put(m[0], counts.getOrDefault(m[0], 0));
            counts.put(m[1], counts.getOrDefault(m[1], 0) + 1);
        }
        
        List<List<Integer>> ret = new ArrayList<>();
        ret.add(new ArrayList<Integer>());
        ret.add(new ArrayList<Integer>());
        
        for (int key: counts.keySet()) {
            if (counts.get(key) == 0) {
                ret.get(0).add(key);
            }
            else if (counts.get(key) == 1) {
                ret.get(1).add(key);
            }
        }
        return ret;
        
    }
}
