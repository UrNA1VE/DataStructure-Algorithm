# https://leetcode.com/problems/validate-stack-sequences/ 

class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack = []
        i, j, n = 0, 0, len(pushed)
        while i < n:
            if not stack:
                stack.append(pushed[i])
                i += 1
            else:
                if stack[-1] == popped[j]:
                    stack.pop()
                    j += 1
                else:
                    stack.append(pushed[i])
                    i += 1
        while j < n and stack and stack[-1] == popped[j]:
            stack.pop()
            j += 1
        if stack:
            return False
        return True
            
        
        
