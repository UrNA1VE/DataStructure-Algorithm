// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
    int[][] dir = new int[][] {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    public int dfs(int[][] matrix, int[][] visit, int i, int j) {
        if (visit[i][j] != 0) return visit[i][j];
        int current = 1;
        for (int k = 0; k < 4; k++) {
            int x = dir[k][0] + i, y = dir[k][1] + j;
            if (x < 0 || x >= matrix.length || y < 0 || y >= matrix[0].length) continue;
            if (matrix[x][y] > matrix[i][j]) {
                current = Math.max(current, 1 + dfs(matrix, visit, x, y));
            }
        }
        visit[i][j] = current;
        return current;
        
    }
    
    public int longestIncreasingPath(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[][] visit = new int[m][n];
        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(matrix, visit, i, j);
                ret = Math.max(ret, visit[i][j]);
            }
        }
        return ret;
    }
}
