// https://leetcode.com/problems/russian-doll-envelopes/

class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        if (envelopes == null) return 0;
        Arrays.sort(envelopes, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if (a[0] == b[0]) {
                    return b[1] - a[1];
                }
                return a[0] - b[0];
            }
        });
        
        int n = envelopes.length, size = 0;
        int[] dp = new int[n];
        for (int[] e: envelopes) {
            int l = 0, r = size, mid = 0;
            while (l < r) {
                mid = l + (r - l) / 2;
                if (dp[mid] < e[1]) {
                    l = mid + 1;
                }
                else r = mid;
            }
            dp[l] = e[1];
            if (size == l) size++; 
        }
        return size;
        
    }
}
