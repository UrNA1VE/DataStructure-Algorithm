// https://leetcode.com/problems/word-ladder/


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        for (string& s: wordList) {
            words.insert(s);
        }
        if (!words.count(endWord)) return false;
        int n = wordList.size(), count = 0;
        unordered_set<string> visit;
        queue<string> q;
        q.push(beginWord);
        q.push("#");
        visit.insert(beginWord);
        
        while(!q.empty()) {
            string curr = q.front();
            q.pop();
            if (curr == endWord) return count + 1;
            if (curr == "#") {
                count++;
                if (!q.empty()) q.push("#");
                continue;
            }
            
            for (int i = 0; i < curr.length(); i++) {
                char c = curr[i];
                for (int j = 0; j < 26; j++) {
                    curr[i] = 'a' + j;
                    if (words.count(curr) && !visit.count(curr)) {
                        q.push(curr);
                        visit.insert(curr);
                    }
                }
                curr[i] = c;
            }
        }
        return 0;
        
        
    }
};
