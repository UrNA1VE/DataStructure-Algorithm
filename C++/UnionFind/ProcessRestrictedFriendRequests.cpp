// https://leetcode.com/problems/process-restricted-friend-requests/

class Union {
public:
    vector<int> an;
    Union(int n): an(n) {
        iota(an.begin(), an.end(), 0);
    }
    
    bool connected(int p, int q) {
        return an[p] == an[q];
    }
    
    int find(int p) {
        return an[p] == p? p: an[p] = find(an[p]);
    }
    
    void connect(int p, int q) {
        an[find(p)] = find(q);
        return;
    }
};


class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> res;
        Union u(n);
        int p, q, a1, a2, b1, b2;
        for (vector<int>& re: requests) {
            p = re[0];
            q = re[1];
            a1 = u.find(p);
            a2 = u.find(q);
            bool valid = true;
            for (vector<int>& r: restrictions) {
                b1 = u.find(r[0]);
                b2 = u.find(r[1]);
                if ((a1 == b1 && a2 == b2) || (a1 == b2 && a2 == b1)) {
                    valid = false;
                    break;
                }
            }
            res.push_back(valid);
            if (valid) u.connect(p, q);
        }
        return res;
    }
};
