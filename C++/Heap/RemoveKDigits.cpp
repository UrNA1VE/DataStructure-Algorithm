// https://leetcode.com/problems/remove-k-digits/

#define pci pair<char,int> 
class Solution {
public:
    string removeKdigits(string num, int k) {
        priority_queue<pci, vector<pci>> p;
        unordered_set<int> exclude;
        int n = num.length(), cnt = n - k;
        if (n == k) return "0";
        for (int i = 0; i < n && k > 0; i++) {
            if (p.empty() || p.top().first <= num[i]) {
                p.push({num[i], i});
            }
            else {
                while (!p.empty() && p.top().first > num[i] && k > 0) {
                    exclude.insert(p.top().second);
                    p.pop();
                    k--;
                }
                p.push({num[i], i});
            }
        }
        string ret;
        for (int i = 0; i < n && cnt > 0; i++) {
            if (!exclude.count(i)) {
                ret += num[i];
                cnt--;
            }
        }
        
        int m = ret.length(), i = 0;
        while (i < m && ret[i] == '0') {
            i++;
        }
        return i == m ?"0": ret.substr(i);
      
    }
};
