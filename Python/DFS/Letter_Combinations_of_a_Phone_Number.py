# https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == '':
            return []
        res = []
        dic = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}
        def dfs(i, ans):
            if i == len(digits):
                res.append(ans)
            else:
                for char in dic[digits[i]]:
                    ans = ans + char
                    dfs(i + 1, ans)
                    ans = ans[:-1]
        dfs(0, '')
        return res
