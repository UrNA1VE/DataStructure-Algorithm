# https://leetcode.com/problems/daily-temperatures/

class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        stack = []
        res = [0] * len(T)
        for i in range(len(T)):
            while stack and T[stack[-1]] < T[i]:
                idx = stack.pop()
                res[idx] = i - idx
            stack.append(i)
        return res
