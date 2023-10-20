# https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/description/

class Solution:
    def getWordsInLongestSubsequence(self, n: int, words: List[str], groups: List[int]) -> List[str]:
        n = len(words)
        prev = [-1] * n
        dp = [1] * n

        for i in range(1, n):
            for j in range(i):
                if groups[i] == groups[j]:
                    continue
                if len(words[i]) != len(words[j]):
                    continue
                if sum(words[i][k] != words[j][k] for k in range(len(words[i]))) != 1:
                    continue
                if dp[j] + 1 > dp[i]:
                    dp[i] = dp[j] + 1
                    prev[i] = j
        
        curr = dp.index(max(dp))
        ret = []

        while curr != -1:
            ret.append(words[curr])
            curr = prev[curr]
        ret.reverse() 
        return ret            
