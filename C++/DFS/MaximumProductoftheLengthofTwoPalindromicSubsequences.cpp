// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/

class Solution {
public:
    int res = 0;
    bool isP(string& a) {
        int i = 0, j = a.length() - 1;
        while (i < j) {
            if (a[i++] != a[j--]) return false;            
        }
        return true;
    }
    
    void dfs(string& s, string& a, string& b, int i, int n) {
        
        if (i == n && isP(a) && isP(b)) {
            res = max(res, (int)a.length() * (int)b.length());
            return;
        }
        if (i == n) return;
        
        a.push_back(s[i]);
        dfs(s, a, b, i + 1, n);
        a.pop_back();
        
        b.push_back(s[i]);
        dfs(s, a, b, i + 1, n);
        b.pop_back();
        
        dfs(s, a, b, i + 1, n);
        
        return;
        
    }
    
    
    
    
    int maxProduct(string s) {
        int n = s.length();
        string a = "", b = "";
        dfs(s, a, b, 0, n);
        return res;
        
        
        
    }
};
