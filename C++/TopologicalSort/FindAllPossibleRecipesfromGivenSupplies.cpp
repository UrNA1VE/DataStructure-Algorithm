// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        
        unordered_set<string> ss;
        for (string& s: supplies) {
            ss.insert(s);
        }
        
        unordered_map<string, int> indegree;
        for (string& s: recipes) {
            indegree[s] = 0;
        }
        
        int n = recipes.size();
        for (int i = 0; i < n; i++) {
            int m = ingredients[i].size();
            for (int j = 0; j < m; j++) {
                if (!ss.count(ingredients[i][j])) {
                    indegree[recipes[i]]++;
                    graph[ingredients[i][j]].push_back(recipes[i]);
                }
            }
        }
        vector<string> ret;
        queue<string> q;
        for(auto x : indegree){
            if(x.second == 0){
                q.push(x.first);
            }
        }
        while(!q.empty()){
            int c = q.size();
            while(c != 0){
                string tmp = q.front();
                q.pop();
                ret.push_back(tmp);
                for(auto nbr : graph[tmp]){
                    indegree[nbr]--;
                    if(indegree[nbr] == 0)
                        q.push(nbr);
                }
                c--;
            }
        }
        return ret;
        
        
    }
};
