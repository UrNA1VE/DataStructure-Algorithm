// https://leetcode.com/problems/single-number-iii/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0, left = 0, right = 0, lsb = 1;
        for (int num: nums) {
            x ^= num;
        }
        while (!(x & lsb)) {
            lsb <<= 1;
        }
        
        for (int num:nums) {
            if (num & lsb) {
                left ^= num;
            }
            else {
                right ^= num;
            }
        }
        return vector<int> {left, right};
        
        
        
        
        
    }
};
