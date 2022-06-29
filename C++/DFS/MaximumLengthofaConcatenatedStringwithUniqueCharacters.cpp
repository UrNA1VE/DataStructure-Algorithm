// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

class Solution {
public:
    int res = 0;
    int maxLength(vector<string>& arr) {
        int count[26];
        memset(count, 0, sizeof(count));
        int n = arr.size();
        dfs(arr, count, 0, n);
        return res;
        
    }
    
    void dfs(vector<string>& arr, int* count, int curr, int n) {
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 1) return;
            if (count[i] == 1) ans++;
        }
        res = max(res, ans);
        for (int i = curr; i < n; i++) {
            for (char c: arr[i]) count[c - 'a']++;
            dfs(arr, count, i+1, n);
            for (char c: arr[i]) count[c - 'a']--;
        }
        
    } 
};
