# https://leetcode.com/problems/divide-two-integers/

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        flag = 1
        if (divisor > 0 and dividend < 0) or (divisor < 0 and dividend > 0):
            flag = -1
        dividend = abs(dividend)
        divisor = abs(divisor)
        if dividend < divisor:
            return 0
        ans = 0
        remain = dividend
        while divisor <= remain:
            i = 0
            while (divisor << i) <= remain:
                i += 1
            ans += (1 << (i - 1))
            remain -= divisor << (i - 1)
        Min = - (1 << 31)
        Max = (1 << 31) - 1
        return min(max(flag * ans, Min), Max)
