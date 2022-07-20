# https://leetcode.com/problems/number-of-matching-subsequences/

class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        word_dict = defaultdict(list)
        ret = 0
        for word in words:
            word_dict[word[0]].append(word)
            
        for c in s:
            expected_dict = word_dict[c]
            word_dict[c] = []
            for word in expected_dict:
                if len(word) == 1:
                    ret += 1
                else:
                    word_dict[word[1]].append(word[1:])
        return ret
        
