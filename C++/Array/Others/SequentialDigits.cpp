// https://leetcode.com/problems/sequential-digits/

class Solution {
public:
    int helper(int start, int k) {
        if (start + k > 10) return -1;
        int ret = start++;
        for (int i = 1; i < k; i++) {
            ret = ret * 10 + start++;
        }
        return ret;
    }
    
    vector<int> sequentialDigits(int low, int high) {
        int p1 = low, p2 = high;
        int k1 = 1, k2 = 1;
        while (p1 > 10) {
            p1 /= 10;
            k1++;
        }
        while (p2 > 10) {
            p2 /= 10;
            k2++;
        }
        
        vector<int> ret;
        for (int k = k1; k <= k2; k++) {
            for (int i = 1; i < 9; i++) {
                int curr = helper(i, k);
                if (curr >= low && curr <= high) {
                    ret.push_back(curr);
                }
            }
        }
        return ret;
    }
};
