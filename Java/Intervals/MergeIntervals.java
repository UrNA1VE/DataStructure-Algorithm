// https://leetcode.com/problems/merge-intervals/

class Solution {
    public int[][] merge(int[][] intervals) {
        List<int[]> res = new ArrayList<> ();
        int n = intervals.length;
        java.util.Arrays.sort(intervals, new java.util.Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return Integer.compare(a[0], b[0]);
            }
        });
        int[] newI = intervals[0];
        
        for (int i = 1; i < n; i++) {
            int[] I = intervals[i];
            if (I[0] <= newI[1]) {
                newI[1] = Math.max(newI[1], I[1]);
            }
            else {
                res.add(newI);
                newI = I;
            }
        }
        res.add(newI);
        return res.toArray(new int[res.size()][]);
        
    }
}
