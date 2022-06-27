// https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length() - 1, n2 = b.length() - 1, carry = 0;
        string res = "";
        while (n1 >= 0 && n2 >= 0) {
            char c1 = a[n1], c2 = b[n2];
            int curr = (c1 - '0') + (c2 - '0') + carry;
            carry = (curr > 1)? 1: 0;
            char now = (curr % 2) ? '1': '0';
            res += now;
            n1--;
            n2--;
        }
        while (n1 >= 0) {
            char c1 = a[n1];
            int curr = (c1 - '0') + carry;
            carry = (curr > 1)? 1: 0;
            char now = (curr % 2) ? '1': '0';
            res += now;
            n1--;
        }
        while (n2 >= 0) {
            char c2 = b[n2];
            int curr = (c2 - '0') + carry;
            carry = (curr > 1)? 1: 0;
            char now = (curr % 2) ? '1': '0';
            res += now;
            n2--;
        }
        if (carry == 1) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};
