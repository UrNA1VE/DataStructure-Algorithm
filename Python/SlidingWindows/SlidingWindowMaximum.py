# https://leetcode.com/problems/sliding-window-maximum/

from collections import deque
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        queue = deque()
        res = []
        for i in range(len(nums)):
            if i - k >= 0:
                res.append(nums[queue[0]])
                while queue and queue[0] <= i - k:
                    queue.popleft()
            while queue and nums[queue[-1]] < nums[i]:
                queue.pop()
            queue.append(i)
        res.append(nums[queue[0]])
        return res
