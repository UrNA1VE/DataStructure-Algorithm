# https://leetcode.com/problems/falling-squares/

class Solution:
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        intervals = []
        n = len(positions)
        ret = []
        h = 0
        for p in positions:
            start = p[0]
            end = p[0] + p[1] - 1
            height = p[1]
            pre_height = 0
            for interval in intervals:
                if start > interval[1] or end < interval[0]:
                    continue
                pre_height = max(pre_height, interval[2])
            intervals.append([start, end, pre_height + height])
            h = max(pre_height + height, h)
            ret.append(h)
        return ret
            
