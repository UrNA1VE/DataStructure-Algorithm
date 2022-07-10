# https://leetcode.com/problems/smallest-number-in-infinite-set/

class SmallestInfiniteSet:

    def __init__(self):
        self.added_set = set()
        self.added_pq = []
        self.next = 0

    def popSmallest(self) -> int:
        if self.added_pq:
            curr = heappop(self.added_pq)
            self.added_set.remove(curr)
            return curr
        else:
            self.next += 1
            return self.next

    def addBack(self, num: int) -> None:
        if self.next >= num and num not in self.added_set:
            self.added_set.add(num)
            heappush(self.added_pq, num)
        
        
