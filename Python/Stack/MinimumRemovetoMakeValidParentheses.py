# https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack = []
        stack2 = []
        n = len(s)
        for i in range(n):
            if s[i] == '(':
                stack.append(i)
            elif s[i] == ')':
                if stack:
                    stack.pop()
                else:
                    stack2.append(i)
        ret = ""
        for i in range(n):
            if i not in stack and i not in stack2:
                ret += s[i]
            
        return ret
        
