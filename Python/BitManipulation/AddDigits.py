# https://leetcode.com/problems/add-digits/

class Solution:
    def addDigits(self, num: int) -> int:
        def helper(num):
            if num < 10:
                return num
            else:
                k = 0
                while num >= 10:
                    k += num % 10
                    num = num // 10
                k += num
                return helper(k) 
        return helper(num)
