// https://leetcode.com/problems/count-the-hidden-sequences/

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size() + 1;
        vector<long long> presum(n, 0);
        for (int i = 0; i < n - 1; i++) {
            presum[i + 1] = presum[i] + differences[i];
        }
        
        auto [l, r] = minmax_element(presum.begin(), presum.end());
        
        int ll = *l - lower, rr = upper - *r;
        return (max(0, ll + rr + 1));
    }
};
