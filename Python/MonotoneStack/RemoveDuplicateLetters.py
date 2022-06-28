# https://leetcode.com/problems/remove-duplicate-letters/

class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        m = dict()
        for i in range(len(s)):
            m[s[i]] = i
        
        stack = []
        visit = set()
        for i in range(len(s)):
            x = s[i]
            if x in visit: continue
            while stack and i < m[stack[-1]] and stack[-1] > x:
                c = stack[-1]
                visit.remove(c)
                stack.pop()
            stack.append(x)
            visit.add(x)
        ret = ""
        for c in stack:
            ret += c
        return ret
        
