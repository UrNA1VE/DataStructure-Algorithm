// https://leetcode.com/problems/maximum-score-of-a-node-sequence/

class Solution {
    public int maximumScore(int[] scores, int[][] edges) {
        int n = scores.length, ret = -1;
        PriorityQueue<Integer>[] q = new PriorityQueue[n];
        for (int i = 0; i < n; i++) {
            q[i] = new PriorityQueue<Integer> ((a, b) -> scores[a] - scores[b]);
        }
        for (int[] edge: edges) {
            q[edge[0]].offer(edge[1]);
            q[edge[1]].offer(edge[0]);
            if (q[edge[0]].size() > 3) {
                q[edge[0]].poll();
            }
            if (q[edge[1]].size() > 3) {
                q[edge[1]].poll();
            }
        }
        
        for (int[] edge: edges) {
            int x = edge[0], y = edge[1];
            for (int i: q[x]) {
                for (int j: q[y]) {
                    if (i != j && i != y && j != x) {
                        ret = Math.max(ret, scores[i] + scores[j] + scores[x] + scores[y]);
                    }
                }
            } 
        }
        return ret;
    }
}
