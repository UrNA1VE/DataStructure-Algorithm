# https://leetcode.com/problems/advantage-shuffle/

class Solution:
    def advantageCount(self, A: List[int], B: List[int]) -> List[int]:
        sortedA = sorted(A)
        sortedB = sorted(B)
        dic = {b:[] for b in B}
        remaining = []
        j = 0
        for a in sortedA:
            if a > sortedB[j]:
                dic[sortedB[j]].append(a)
                j += 1
            else:
                remaining.append(a)
        res = [dic[b].pop() if dic[b] else remaining.pop() for b in B]
        return res
        
