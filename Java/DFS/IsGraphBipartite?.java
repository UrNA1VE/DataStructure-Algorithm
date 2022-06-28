// https://leetcode.com/problems/is-graph-bipartite/

class Solution {
    
    public boolean helper(int[][] graph, int[] colors, int color, int node) {
        if (colors[node] != 0) {
            return colors[node] == color;
        }
        colors[node] = color;
        for (int next: graph[node]) {
            if (!helper(graph, colors, -color, next)) {
                return false;
            }
        }
        return true;
    }
    
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] colors = new int[n];
        
        for (int i = 0; i < n; i++) {
            if (colors[i] == 0 && !helper(graph, colors, 1, i)) {
                return false;
            }
        }
        return true;
    }
}
