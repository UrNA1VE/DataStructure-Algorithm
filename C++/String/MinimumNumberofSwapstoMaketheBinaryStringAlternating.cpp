// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/

class Solution {
public:
    int minSwaps(string s) {
        int count1 = 0, count0 = 0, n = s.length();
        for (int i = 0; i < n; i ++){
            if (s[i] == '1') count1++;
            else count0++;
        }
        if (abs(count1 - count0) > 1) return -1;
        int res = 0;
        
        if (abs(count1 - count0) == 1){
            char c;
            if (count1 - count0 == 1){
                c = '1';
            }
            else {
                c = '0';
            }
            for (int i = 0; i < n; i += 2){
                if (s[i] != c) res++;
            }
            return res;
        }
        else{
            int pos0 = 0;
            for (int i = 0; i < n; i += 2){
                if (s[i] != '0') pos0++;
            }
            return min(pos0, n / 2 - pos0);
            
        }
        
    }
};
