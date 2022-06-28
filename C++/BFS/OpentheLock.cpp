// https://leetcode.com/problems/open-the-lock/

class Solution {
public:
    unordered_set<string> table;
    unordered_set<string> locks;
    queue<string> process;
    
    void helper(const string& s) {
        if (table.find(s) != table.cend()) return;
        table.insert(s);
        for (int i = 0; i < 4; i ++) {
            string new1 = s;
            string new2 = s;
            if (s[i] == '0') {
                new1[i] = '1';
                new2[i] = '9';
            }
            else if (s[i] == '9') {
                new1[i] = '8';
                new2[i] = '0';
            }
            else {
                new1[i] -= 1;
                new2[i] += 1;
            }
            
            if (locks.find(new1) == locks.cend() && table.find(new1) == table.cend()) {
                process.push(new1);
            }
            if (locks.find(new2) == locks.cend() && table.find(new2) == table.cend()) {
                process.push(new2);
            }
   
        }
    }
    
    int openLock(vector<string>& deadends, string target) {
        locks = unordered_set<string> (deadends.begin(), deadends.end());
        if (locks.find("0000") != locks.cend()) return -1;

        int res = 0;
        process.push("0000");
        process.push("#");
        
        while (!process.empty()) {
            string s = process.front();
            process.pop();
            if (s == "#") {
                if (process.empty()) return -1;
                res ++;
                process.push("#");
                continue;
            }
            else {
                if (s == target) return res;
                helper(s);
            }
        }
        return -1;
    }
};




