# https://leetcode.com/problems/minimum-number-of-refueling-stops/

class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        hp = []
        ret = 0
        for s in stations:
            if startFuel >= target:
                return ret
            while hp and startFuel < s[0]:
                startFuel -= heapq.heappop(hp)
                ret += 1
            if startFuel < s[0]:
                return -1 
            heapq.heappush(hp, -s[1])
        
        while hp and startFuel < target:
            startFuel -= heapq.heappop(hp)
            ret += 1
        
        return ret if startFuel >= target else -1
            
