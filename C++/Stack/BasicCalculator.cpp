// https://leetcode.com/problems/basic-calculator/


class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int n = s.length();
        vector<int> op(2, 1);
        for (int i = 0; i < n; i ++) {
            char c = s[i];
            if (s[i] >= '0') {
                int num = 0;
                while (i < n && s[i] >= '0') {
                    num = 10*num + (s[i++] - '0');
                }
                res += op.back() * num;
                op.pop_back();
                i--;
            }
            else if (c == ')') {
                op.pop_back();
            }
            else if (c != ' ') {
                op.push_back(op.back() * ((c == '-')? -1: 1));
            }
        }
        return res;
        
    }
};
