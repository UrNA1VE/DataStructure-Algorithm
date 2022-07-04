// https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/

class Solution {
    public int helper(ArrayList<Integer> arr, int x) {
        int l = 0, r = arr.size() - 1;
        int ret = arr.size();
        while (l <= r) {
            int mid = l + (r - l) /2;
            if (arr.get(mid) >= x) {
                ret = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ret;
    }
    public int[] countRectangles(int[][] rectangles, int[][] points) {
        Map<Integer, ArrayList<Integer>> arrs = new HashMap<>();
        for (int[] rec: rectangles) {
            if (!arrs.containsKey(rec[1])) {
                arrs.put(rec[1], new ArrayList<>());
            }
            arrs.get(rec[1]).add(rec[0]);
        }
        
        for (int key: arrs.keySet()) {
            Collections.sort(arrs.get(key));
        }
        int n = points.length;
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1], cnt = 0;
            for (int j = y; j <= 100; j++) {
                if (arrs.containsKey(j)) {
                    cnt += arrs.get(j).size() - helper(arrs.get(j), x);
                }
            }
            ret[i] = cnt;
        }
        return ret;
        
    }
}
