// https://leetcode.com/problems/longest-path-with-different-adjacent-characters/

class Solution {
    int ret = 0;
    
    public int longestPath(int[] parent, String s) {
        int n = parent.length;
        ArrayList<Integer>[] children = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            children[i] = new ArrayList<>();
        }
        
        for (int i = 1; i < n; i++) {
            children[parent[i]].add(i);
        }
        dfs(children, s, 0);
        return ret;
        
    }
    
    public int dfs(ArrayList<Integer>[] children, String s, int i) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int j: children[i]) {
            int curr = dfs(children, s, j);
            if (s.charAt(i) != s.charAt(j)) {
                pq.add(-curr);
            }
        }
        int res1 = pq.isEmpty()? 0: -pq.poll();
        int res2 = pq.isEmpty()? 0: -pq.poll();
        ret = Math.max(ret, res1 + res2 + 1);
        return res1 + 1;
    }
}
