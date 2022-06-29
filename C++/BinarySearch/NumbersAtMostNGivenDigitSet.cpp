// https://leetcode.com/problems/numbers-at-most-n-given-digit-set/


class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int> d;
        vector<int> di;
        for (string& s:digits) {
            di.push_back(s[0] - '0');
        }
        int temp = n, n_di = digits.size();
        while (temp > 0) {
            d.push_back(temp%10);
            temp /= 10;
        }
        reverse(d.begin(), d.end());
        int n_d = d.size(), res = 0;
        temp = 1;
        for (int i = 1; i < n_d; i++) {
            temp *= n_di;
            res += temp;
        }
        
        for (int i = 0; i < n_d; i++) {
            auto it = lower_bound(di.begin(), di.end(), d[i]);
            res += temp * (it - di.begin());
            if (it == di.end() || *it != d[i]) break;
            if (i == n_d - 1) res++;
            temp /= n_di;
        }
        return res;
        
    }
};
