# https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        ans = 0
        for i in range(len(heights) + 1):
            h = heights[i] if i < len(heights) else 0
            while stack and heights[stack[-1]] >= h:
                pre = stack.pop()
                height = heights[pre]
                width = i - 1 - (stack[-1] if stack else -1)
                ans = max(ans, height * width)
            stack.append(i)
        return ans
