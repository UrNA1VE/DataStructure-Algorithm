// https://leetcode.com/problems/find-all-people-with-secret/

class UnionFind {
public:
    vector<int> id;
    
    UnionFind(int n): id(n) {
        iota(id.begin(), id.end(), 0);
    }
    
    void connect(int a, int b) {
        id[find(b)] = find(a);
    }
    
    int find(int a) {
        return id[a] == a? a: (id[a] = find(id[a]));
    }
    
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    
    void reset(int a) {
        id[a] = a;
    }
    
};

bool cmp(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}
class Solution {
public:
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), cmp);
        vector<int> temp;
        UnionFind uf(n);
        uf.connect(0, firstPerson);
        int m = meetings.size();
        
        for (int i = 0; i < m;) {
            int time = meetings[i][2];
            temp.clear();
            for (; i < m && meetings[i][2] == time; i++) {
                uf.connect(meetings[i][0], meetings[i][1]);
                temp.push_back(meetings[i][0]);
                temp.push_back(meetings[i][1]);
            }
            
            for (int x: temp) {
                if (!uf.connected(0, x)) uf.reset(x);
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (uf.connected(0, i)) res.push_back(i);
        }
        return res;
        
    }
};
