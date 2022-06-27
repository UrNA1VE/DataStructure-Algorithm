// https://leetcode.com/problems/insert-interval/

class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        if (intervals == null) return new int[][] {newInterval};
        List<int[]> res = new ArrayList<> ();
        for (int[] interval: intervals) {
            if (interval[1] < newInterval[0]) {
                res.add(interval);
            }
            else if (interval[0] > newInterval[1]) {
                res.add(newInterval);
                newInterval = interval;
            }
            else {
                newInterval[0] = Math.min(newInterval[0], interval[0]);
                newInterval[1] = Math.max(newInterval[1], interval[1]);
            }
        }
        res.add(newInterval);
        return res.toArray(new int[res.size()][]);
        
        
    }
}
