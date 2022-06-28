// https://leetcode.com/problems/trapping-rain-water-ii/

class Solution {
public:
    typedef pair<int, int> cell;
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        int m = heightMap.size(), n = heightMap[0].size(), res = 0;
        unordered_set<int> visited;
        priority_queue<cell, vector<cell>, greater<cell>> q;
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    visited.insert(i * n + j);
                    q.push(cell(heightMap[i][j], i * n + j));
                }
            }
        }
        vector<vector<int>> dir {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int i, j, new_i, new_j, new_inj;
        
        while (!q.empty()) {
            cell curr = q.top();
            q.pop();
            i = curr.second / n;
            j = curr.second % n;
            for (int r = 0; r < 4; r++) {
                new_i = i + dir[r][0];
                new_j = j + dir[r][1];
                new_inj = new_i * n + new_j;
                if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || visited.find(new_inj) != visited.cend()) continue;
                res += max(0, curr.first - heightMap[new_i][new_j]);
                q.push(cell(max(curr.first, heightMap[new_i][new_j]), new_inj));
                visited.insert(new_inj);
            }
            
        }
        return res;
        
    }
};
