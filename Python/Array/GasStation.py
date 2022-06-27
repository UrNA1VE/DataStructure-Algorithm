# https://leetcode.com/problems/gas-station/

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas) < sum(cost):
            return -1
        start = 0
        count = gas[0] - cost[0]
        gas[0] = count
        cost[0] = count
        start1 = 0
        for i in range(1, len(gas)):
            gas[i] = gas[i] - cost[i]
            if cost[i - 1] < 0:
                cost[i] = gas[i]
                start1 = i
            else:
                cost[i] = cost[i - 1] + gas[i]
            if cost[i] > count:
                count = cost[i]
                start = start1
        pre = cost[-1]
        start2 = start1
        for i in range(0, start1):
            if pre < 0:
                cost[i] = max(cost[i], gas[i])
                start2 = i
            else:
                pre = pre + gas[i]
            if pre > count:
                count = pre
                start = start2

        return start
