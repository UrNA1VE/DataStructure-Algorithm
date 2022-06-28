# https://leetcode.com/problems/fraction-to-recurring-decimal/

class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        def long_div(top, bottom):
            res = 0
            for i in range(32, -1, -1):
                if (bottom << i) <= top:
                    top -= (bottom << i)
                    res += (1 << i)
            return res, top
        if numerator == 0:
            return '0'
        neg = (numerator < 0) ^ (denominator < 0)
        q, r = long_div(abs(numerator), abs(denominator))
        s = str(q)
        if neg:
            s = '-' + s
        if r:
            s = s + '.'
        i = len(s)
        nums = {r: i}
        while r:
            q, r = long_div((r << 3) + (r << 1), abs(denominator))
            s += str(q)
            if r in nums:
                s = s[:nums[r]] + '(' + s[nums[r]:] + ')'
                return s
            i += 1
            nums[r] = i
        return s
