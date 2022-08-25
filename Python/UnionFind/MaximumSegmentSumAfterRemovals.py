# https://leetcode.com/problems/maximum-segment-sum-after-removals/

class UnionFind:
    def __init__(self):
        self.sums = {}
        self.parents = {}
        self.ret = 0
        
    def find(self, u):
        if self.parents[u] != u:
            self.parents[u] = self.find(self.parents[u])
        return self.parents[u]
    
    def addAndMerge(self, u, value):
        self.parents[u] = u
        self.sums[u] = value
        self.ret = max(self.ret, value)
        if u + 1 in self.parents:
            self.union(u, u + 1)
        if u - 1 in self.parents:
            self.union(u, u - 1)
    
    def union(self, u, v):
        u = self.find(u)
        v = self.find(v)
        if u == v: return
        self.sums[u] += self.sums[v]
        self.parents[v] = u
        self.ret = max(self.ret, self.sums[u])

class Solution:
    def maximumSegmentSum(self, nums: List[int], removeQueries: List[int]) -> List[int]:
        n = len(nums)
        ret = [0] * n
        uf = UnionFind()
        for i in range(n - 1, -1, -1):
            ret[i] = uf.ret
            uf.addAndMerge(removeQueries[i], nums[removeQueries[i]])
        return ret
