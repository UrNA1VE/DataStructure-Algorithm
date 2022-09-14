# https://leetcode.com/problems/maximum-number-of-robots-within-budget/

class Solution:
    def maximumRobots(self, chargeTimes: List[int], runningCosts: List[int], budget: int) -> int:
        i, n, curr = 0, len(chargeTimes), 0
        dq = deque()
        for j in range(n):
            while dq and chargeTimes[dq[-1]] <= chargeTimes[j]:
                dq.pop()
            dq.append(j)
            curr += runningCosts[j]
            if chargeTimes[dq[0]] + (j - i + 1) * curr > budget:
                if dq[0] == i:
                    dq.popleft()
                curr -= runningCosts[i]
                i += 1
        return n - i
            
            
        
