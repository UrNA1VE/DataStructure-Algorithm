// https://leetcode.com/problems/escape-the-spreading-fire/

class Solution {
    
    int[][] dir = new int[][]{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    public int[][] clone(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] copy = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                copy[i][j] = grid[i][j];
            }
        }
        return copy;
    }
    
    public int maximumMinutes(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        List<int[]> fires = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fires.add(new int[]{i, j});
                }
            }
        }
        
        int l = 0, r = m * n, ret = 0;
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (possible(grid, mid, fires)) {
                ret = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        if (r < 0) return -1;
        if (l > m*n) return (int) 1e9;
        return ret;
    }
    
    public boolean possible(int[][] grid, int mid, List<int[]> fires) {
        int[][] copy = clone(grid);
        Queue<int[]> fire = new LinkedList<>();
        fire.addAll(fires);
        while (mid-- > 0 && !fires.isEmpty()) {
            if (spread(fire, copy)) return false;;
        }
        
        Queue<int[]> p = new LinkedList<>();
        p.add(new int[]{0, 0});
        while (!p.isEmpty()) {
            boolean flag = spread(fire, copy);
            if (spread(p, copy)) return true;
            if (flag) return false;
        }
        return false;
    }
    
    public boolean spread(Queue<int[]> q, int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int size = q.size();
        while (size-- > 0) {
            int[] pos = q.remove();
            
            for (int k = 0; k < 4; k++) {
                int x = pos[0] + dir[k][0], y = pos[1] + dir[k][1];
                if (x == m - 1 && y == n - 1) {
                    return true;
                }
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0) {
                    grid[x][y] = -1;
                    q.add(new int[]{x, y});
                }
            }
        }
        return false;
    }
    
}
