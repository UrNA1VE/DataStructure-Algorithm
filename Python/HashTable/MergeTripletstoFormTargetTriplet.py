# https://leetcode.com/problems/merge-triplets-to-form-target-triplet/

class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        table = defaultdict(list)
        n = len(triplets)
        for i in range(n):
            x= triplets[i]
            if (x[0] == target[0] and x[1] <= target[1] and x[2] <= target[2]):
                table[0].append(i)
            if (x[1] == target[1] and x[0] <= target[0] and x[2] <= target[2]):
                table[1].append(i)
            if (x[2] == target[2] and x[1] <= target[1] and x[0] <= target[0]):
                table[2].append(i)
        for i in range(3):
            if not table[i]:
                return False
        return True
            
            
