# https://leetcode.com/problems/valid-parentheses/

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        v = ['(', '[', '{']
        for c in s:
            if c in v:
                stack.append(c)
            else:
                if not stack:
                    return False
                if c == ')':
                    if stack[-1] == '(':
                        stack.pop()
                    else:
                        return False
                elif c == '}':
                    if stack[-1] == '{':
                        stack.pop()
                    else:
                        return False
                elif c == ']':
                    if stack[-1] == '[':
                        stack.pop()
                    else:
                        return False
        if stack: return False
        return True
