# https://leetcode.com/problems/shifting-letters-ii/

class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n = len(s)
        cnt = [0] * (n + 1)
        for shift in shifts:
            if shift[2] == 1:         
                cnt[shift[0]] += 1
                cnt[shift[1] + 1] -= 1
            else:
                cnt[shift[0]] -= 1
                cnt[shift[1] + 1] += 1
        curr = 0
        ret = ""
        
        for i in range(n):
            curr += cnt[i]
            ret += chr(97 + (ord(s[i]) - 97 + 26 + curr) % 26)
        return ret
