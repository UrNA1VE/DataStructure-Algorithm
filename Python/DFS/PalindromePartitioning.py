# https://leetcode.com/problems/palindrome-partitioning/

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        def ispalindrome(s):
            return s == s[::-1]
        def palinpart(s, index, ans):
            if index == len(s):
                res.append(ans[:])
                return
            for i in range(index, len(s)):
                if ispalindrome(s[index: i + 1]):
                    temp = s[index: i + 1]
                    ans.append(temp)
                    palinpart(s, i + 1, ans)
                    ans.pop()
        palinpart(s, 0, [])
        return res
