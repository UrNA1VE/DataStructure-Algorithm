// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size(), count1 = 0, count2 = 0;
        bool flag = false;
        unordered_map<string, int> m;
        for (string x: words) {
            if (m.count(x) && m[x] > 0) {
                m[x]--;
                if (x[0] == x[1]) {
                    count1++;
                }
                else count2++;
            }
            else{
                reverse(x.begin(), x.end());
                if (m.count(x)) m[x]++;
                else m[x] = 1;
            }
        }
        for (auto x: m) {
            if (x.first[0] == x.first[1] && x.second == 1) {
                flag = true;
                break;
            }
        }
        
        int ret = (flag)? 2: 0;
        ret += 4*(count1 + count2);
        return ret;
        
        
    }
};
