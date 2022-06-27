# https://leetcode.com/problems/longest-common-prefix/


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = []
        for i in zip(*strs):
            if len(set(i)) == 1:
                prefix.append(i[0])
            else:
                break
        return ''.join(prefix)
