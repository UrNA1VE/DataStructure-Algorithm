// https://leetcode.com/problems/remove-invalid-parentheses/

class Solution {
private:
    int k = INT_MIN;
    bool isvalid(string s) {
        int count = 0, n = s.size();
        for (char letter: s) {
            if (letter == '(') count ++;
            if (letter == ')') count --;
            if (count < 0) return false;
        }
        return count==0;
    }
    
public:
    void dfs(string s, int start, unordered_set<string>& res) {
        int n = s.length();
        if (start == n && isvalid(s)) {
            if (n == k) {
                res.insert(s);
            }
            else if (n > k) {
                res.clear();
                res.insert(s);
                k = n;
            }
            return;
        }
        if (start >= n) return;
        if (s[start] != '(' && s[start] != ')') {
            dfs(s, start + 1, res);
        }
        else{
            string new_s1 = s.substr(0, n);
            string new_s2 = s.substr(0, start) + s.substr(start + 1, n);
            dfs(new_s1, start + 1, res);
            dfs(new_s2, start, res);
            
        }
        return;

    }
    
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> res;
        dfs(s, 0, res);
        vector<string> ret;
        for (string x: res) {
            ret.push_back(x);
        }
        if (ret.empty()) ret.push_back("");
        return ret;
        
    }
};
