# https://leetcode.com/problems/longest-ideal-subsequence/

class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        position = defaultdict(int)
        ret = 1
        for c in s:
            curr = ord(c)
            for pre in range(max(97, curr - k), min(122, curr + k) + 1):
                if pre in position:
                    position[curr] = max(position[curr], position[pre])
            position[curr] += 1
            ret = max(ret, position[curr])
        return ret
        
        
        
