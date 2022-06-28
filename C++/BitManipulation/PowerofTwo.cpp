// https://leetcode.com/problems/power-of-two/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int base = 1;
        if (n == base) return true;
        for (int i = 1; i < 32; i ++) {
            base <<= 1;
            if (base == n) return true;
            if (base > n) break;
        }
        return false;
        
    }
};
