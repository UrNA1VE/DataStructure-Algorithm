# https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        n, ret, curr = len(blocks), k, 0
        for i in range(k):
            if blocks[i] == 'B':
                curr += 1
        ret = min(ret, k - curr)
        for i in range(k, n):
            if blocks[i] == "B":
                curr += 1
            if blocks[i - k] == "B":
                curr -= 1
            ret = min(ret, k - curr)
        return ret
            
            
