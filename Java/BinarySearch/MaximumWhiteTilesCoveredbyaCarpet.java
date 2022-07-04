// https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/

class Solution {
    public int binary(int[][] tiles, int l, int r, int end) {
        int ret = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (tiles[mid][0] <= end && tiles[mid][1] >= end) {
                return mid;
            }
            else if (tiles[mid][1] <= end) {
                ret = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ret;
        
    }
    
    public int maximumWhiteTiles(int[][] tiles, int carpetLen) {
        int ret = 0;
        int n = tiles.length;
        long[] presum = new long[n];
        Arrays.sort(tiles, (a, b) -> a[0] - b[0]);
        presum[0] = tiles[0][1] - tiles[0][0] + 1;
        for (int i = 1; i < n; i++) {
            presum[i] = presum[i - 1] + tiles[i][1] - tiles[i][0] + 1;
        }
        
        for (int i = 0; i < n; i++) {
            int end = tiles[i][0] + carpetLen - 1;
            int idx = binary(tiles, i, n - 1, end);
            
            if (end >= tiles[idx][1]) {
                ret = Math.max(ret, (int) (presum[idx] - (i > 0? presum[i - 1]: 0)));
            }
            else {
                ret = Math.max(ret, (int) (presum[idx] - (i > 0? presum[i - 1]: 0) - (tiles[idx][1] - end)));
            }
        }
        return ret;
    }
}
