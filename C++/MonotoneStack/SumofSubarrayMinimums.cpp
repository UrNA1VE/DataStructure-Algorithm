// https://leetcode.com/problems/sum-of-subarray-minimums/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 +7;
        vector<int> s;
        long long res = 0;
        
        
        for (int i = 0; i <= n; i++) {
            while (!s.empty() && (i == n || arr[s.back()] > arr[i])) {
                int j = s.back(), k = s.size() < 2? -1: s[s.size() - 2];
                res += (long long) (i - j) * (j - k) * arr[j];
                s.pop_back();
            }
            s.push_back(i);
        }
        return (int) (res % mod);
        
    }
};
