// https://leetcode.com/problems/maximum-product-of-word-lengths/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), res = 0;
        vector<int> masks(n, 0);
        for(int i = 0; i < n; i++) {
            string word = words[i];
            for(auto x: word) {
                masks[i] |= 1<<(x - 'a');
            }
            
            for(int j = 0; j < i; j++) {
                if (!(masks[i] & masks[j])) {
                    res = max(res, int (words[i].length() * words[j].length()));
                }
                
            }
            
        }
        return res;
    }
};
