# https://leetcode.com/problems/describe-the-painting/

class Solution:
    def splitPainting(self, segments: List[List[int]]) -> List[List[int]]:
        helper = defaultdict(int)
        ret = []
        for start, end, color in segments:
            helper[start] += color
            helper[end] -= color
        
        pre = 0
        preidx = 0
        for i in sorted(helper.keys()):
            if pre != 0:
                ret.append([preidx, i, pre])
            pre += helper[i]
            preidx = i
        return ret
                
                
