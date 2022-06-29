# https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        n, ret = len(tops), 2*10**4
        for k in range(1, 7):
            up = 0
            flag = True
            equal = 0
            for i in range(len(tops)):
                if tops[i] != k and bottoms[i] != k:
                    flag = False
                    break
                if tops[i] == k and bottoms[i] == k:
                    equal += 1
                    continue
                if tops[i] == k:
                    up += 1
            if flag:
                ret = min(ret, min(up, n - up - equal))
        return ret if ret != 2*10**4 else -1
                    
        
