# https://leetcode.com/problems/integer-to-roman/

class Solution:
    def intToRoman(self, num: int) -> str:
        roman_dict = {1: 'I', 4: 'IV', 5: 'V', 9: 'IX', 10: 'X', 40: 'XL', 50: 'L', 90: 'XC', 100: 'C', 400: 'CD', 500: 'D', 900: 'CM', 1000: 'M'}
        times = 1
        res = ''
        while num != 0:
            residual = num % 10
            num = num // 10
            if residual == 4 or residual == 9:
                res = roman_dict[residual * times]  + res
            else:
                while residual > 0:
                    if residual == 5:
                        res = roman_dict[5 * times] + res
                        residual -= 5
                    else:
                        res = roman_dict[1 * times] + res
                        residual -= 1
            times = times * 10
        return res
