# https://leetcode.com/problems/two-city-scheduling/

class Solution:

    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        N = len(costs)//2
        dp = {}
        def helper(i, A, B):
            if (i, A, B) in dp:
                return dp[(i, A, B)]
            if A == N and B == N:
                return 0
            elif A == N:
                dp[(i, A, B)] = helper(i + 1, A, B + 1) + costs[i][1]
            elif B == N:
                dp[(i, A, B)] = helper(i + 1, A + 1, B) + costs[i][0]
            else:
                dp[(i, A, B)] = min(helper(i + 1, A + 1, B) + costs[i][0], helper(i + 1, A, B + 1) + costs[i][1])
            return dp[(i, A, B)]
        return helper(0, 0, 0)
        
