# https://leetcode.com/problems/group-anagrams/

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic = defaultdict(list)
        for i in strs:
            letters = ''.join(sorted(i))
            dic[letters].append(i)
        return dic.values()
