// https://leetcode.com/problems/decode-string/

class Solution {
public:
    string helper(const string& s, int& i) {
        string res;
        int n = s.length();
        while (i < n && s[i] != ']') {
            if (s[i] >= 'a' && s[i] <= 'z') {
                res += s[i++];
            }
            else {
                int time = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    time = time * 10 + s[i] - '0';
                    i++;
                }
                i++;
                string t = helper(s, i);
                i++;
                for (int j = 0; j < time; j++) {
                    res += t;
                }
            }
        }
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        return helper(s, i);
    }
    
    
};
