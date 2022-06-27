# https://leetcode.com/problems/plus-one/

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        i = len(digits) - 1
        def jinwei(i):
            if i == 0:
                digits.insert(0, 1)
                digits[1] = 0
            if i != 0:
                digits[i] = 0
                digits[i - 1] += 1
        digits[i] += 1
        while i >= 0:
            if digits[i] == 10:
                jinwei(i)
                i -= 1
            else:
                break
        return digits
