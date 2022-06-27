# https://leetcode.com/problems/edit-distance/

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        lookup = {}
        def helper(start, end):
            if start == '' or end == '':
                return len(start) or len(end)
            key = start + '#' + end
            if key in lookup:
                return lookup[key]
            if start[-1] == end[-1]:
                return helper(start[:-1], end[:-1])
            sub = helper(start[:-1], end[:-1]) + 1
            rem = helper(start[:-1], end) + 1
            ins = helper(start, end[:-1]) + 1
            lookup[key] = min(sub, min(rem, ins))
            return lookup[key]
        return helper(word1, word2)
