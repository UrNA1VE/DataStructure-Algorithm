// https://leetcode.com/problems/parallel-courses-iii/

class Solution {
    public int minimumTime(int n, int[][] relations, int[] time) {
        int[] indegree = new int[n];
        int[] dist = new int[n];
        ArrayList<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int[] r: relations) {
            int pre = r[0] - 1, next = r[1] - 1;
            graph[pre].add(next);
            indegree[next]++;
        }
        
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.add(i);
                dist[i] = time[i];
            }
        }
        while (!q.isEmpty()) {
            int curr = q.poll();
            for (int next: graph[curr]) {
                dist[next] = Math.max(dist[next], dist[curr] + time[next]);
                if (--indegree[next] == 0) {
                    q.add(next);
                }
            }
        }
        
        int ret = 0;
        for (int i = 0; i< n; i++) {
            ret = Math.max(ret, dist[i]);
        }
        return ret;
        
    }
}
