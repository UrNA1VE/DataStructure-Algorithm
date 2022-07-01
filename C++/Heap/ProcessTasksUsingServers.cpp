// https://leetcode.com/problems/process-tasks-using-servers/

struct node
{
    int index, value;
    node(int index,int value):index(index),value(value){}
};
 
bool operator< (node a,node b)
{
    if (a.value != b.value) return a.value > b.value;
    else return a.index > b.index;
}

class Solution {
public:
    
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        
        int n = tasks.size(), m = servers.size();
        priority_queue<node> free_server;
        priority_queue<node> running_server;
        
        for (int j = 0; j < m; j ++) {
            free_server.push(node(j, servers[j]));
        }
        
        int time = 0, i = 0;
        vector<int> res;
        while (i < n) {
            
            while (!running_server.empty() && running_server.top().value <= time) {
                int r = running_server.top().index;
                running_server.pop();
                free_server.push(node(r, servers[r]));
            }
            
            while (i < n && time >= i && !free_server.empty()) {
                int f = free_server.top().index;
                free_server.pop();
                running_server.push(node(f, time + tasks[i]));
                i ++;
                res.push_back(f);
                
            }
            if (free_server.empty()) {
                time = running_server.top().value;
            }
            else if (time < i) {
                time ++;
                
            }
        }
        return res;
        
        
    }
};
