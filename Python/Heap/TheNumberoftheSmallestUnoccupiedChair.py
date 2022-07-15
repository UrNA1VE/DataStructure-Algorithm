# https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/

from heapq import *
class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        arrives = []
        leaves = []
        target = times[targetFriend][0]
        seats = [i for i in range(len(times))]
        heapify(seats)
        d = {}
        for i, (x, y) in enumerate(times):
            heappush(arrives, (x, i))
            heappush(leaves, (y, i))
        
        while True:
            if arrives[0][0] < leaves[0][0]:
                (x, i) = heappop(arrives)
                seat = heappop(seats)
                d[i] = seat
                if target == x:
                    return seat
            else :
                (x, i) = heappop(leaves)
                seat = d[i]
                heappush(seats, seat)
                
                
            
