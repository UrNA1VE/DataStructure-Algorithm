// https://leetcode.com/problems/maximize-distance-to-closest-person/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size(), pre, maxDis = 0, first, last;
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                first = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (seats[i] == 1) {
                last = i;
                break;
            }
        }
        pre = first;
        for (int i = first + 1; i <= last; i++) {
            if (seats[i] == 1) {
                maxDis = max(maxDis, i - pre);
                pre = i;
            }
        }
        return max(first, max(n - 1 - last, maxDis / 2));
    }
};
