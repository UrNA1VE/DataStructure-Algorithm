# https://leetcode.com/problems/construct-smallest-number-from-di-string/

class Solution:
    def smallestNumber(self, pattern: str) -> str:
        pattern += "I"
        curr, ret = [], []
        for i, p in enumerate(pattern):
            curr.append(str(i + 1))
            if p == 'I':
                ret += curr[::-1]
                curr = []
        return ''.join(ret)
                
