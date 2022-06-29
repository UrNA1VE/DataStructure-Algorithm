# https://leetcode.com/problems/word-subsets/

class Solution:
    def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
        helper = defaultdict(int)
        res = []
        for b in B:
            dic = Counter(b)
            for letter in dic:
                helper[letter] = max(helper[letter], dic[letter])

        for a in A:
            dic = Counter(a)
            if all(helper[letter] <= dic[letter] for letter in helper):
                res.append(a)
        return res
