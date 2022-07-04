# https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

class unionFind:
    def __init__(self, n):
        self.root = [i for i in range(n)]
        self.rank = [1] * n
        
    def find(self, i):
        if i == self.root[i]:
            return i
        return self.find(self.root[i])
    
    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.root[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.root[rootX] = rootY
            else:
                self.root[rootY] = rootX
                self.rank[rootX] += 1

        
class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        UF = unionFind(n)
        for u, v in edges:
            UF.union(u, v)
        C = list(Counter([UF.find(i) for i in range(n)]).values())
        ans = 0
        firstGroupCount = C[0]
        for i in range(1, len(C)):
            ans += firstGroupCount * C[i]
            firstGroupCount += C[i]  
        return ans
        
