# https://leetcode.com/problems/jump-game-vi/

class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        ms = deque([0])
        ret, n = nums[0], len(nums)
        for i in range(1, n):
            nums[i] += nums[ms[0]]
            while ms and nums[ms[-1]] < nums[i]:
                ms.pop()
            ms.append(i)
            if ms[0] + k == i:
                ms.popleft()
        return nums[n - 1]
            
