# https://leetcode.com/problems/random-flip-matrix/

class Solution:

    def __init__(self, m: int, n: int):
        self.m = m
        self.n = n
        self.all = m*n - 1
        self.s = set()

    def flip(self) -> List[int]:
        while True:
            k = randint(0, self.all)
            i = k% self.m
            j = k//self.m
            if (i, j) not in self.s:
                self.s.add((i, j))
                return [i, j]
        

    def reset(self) -> None:
        self.s.clear()
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(m, n)
# param_1 = obj.flip()
# obj.reset()
