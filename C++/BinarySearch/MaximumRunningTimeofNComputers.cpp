// https://leetcode.com/problems/maximum-running-time-of-n-computers/

class Solution {
public:
    bool helper(vector<int>& batteries, long long time, int n) {
        long long ttime = time * n;
        for (long long x: batteries) {
            ttime -= min(x, time);
        }
        return (ttime <= 0);
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = 0,  r = 0, ret;
        for (int x: batteries) {
            r += x;
        }
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (!helper(batteries, mid, n)) {
                r = mid - 1;
                
            }
            else {
                l = mid + 1;
                ret = mid;
            }
        }
        return ret;
    }
};
