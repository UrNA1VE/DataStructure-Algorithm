// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 0, r = m * n, mid, count;
        while (l < r) {
            mid = (l + r) / 2;
            count = 0;
            for (int i = 0; i < m; i++) {
                count += mid / (i + 1) <= n ? mid / (i + 1) : n;
            }
            
            if (count >= k) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
        
    }
};
