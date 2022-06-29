// https://leetcode.com/problems/critical-connections-in-a-network/

class Solution {
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        List<Integer>[] graph = new ArrayList[n];
        List<List<Integer>> ret = new ArrayList<>();
        for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
        for (List<Integer> edge: connections) {
            graph[edge.get(0)].add(edge.get(1));
            graph[edge.get(1)].add(edge.get(0));
        }
        
        int time = 1;
        int[] timeStamp = new int[n];
        dfs(graph, -1, 0, time, timeStamp, ret);
        return ret;
    }
    
    public void dfs(List<Integer>[] graph, int parent, int node, int time, int[] timeStamp, List<List<Integer>> ret) {
        timeStamp[node] = time++;
        int curr = timeStamp[node];
        for (int next: graph[node]) {
            if (next == parent) continue;
            if (timeStamp[next] == 0) {
                dfs(graph, node, next, time, timeStamp, ret);
            }
            timeStamp[node] = Math.min(timeStamp[node], timeStamp[next]);
            if (curr < timeStamp[next]) {
                ret.add(Arrays.asList(node, next));
            }
        }
    }
}
