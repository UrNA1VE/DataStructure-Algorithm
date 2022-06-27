# Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

# Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

# Input: x = 123
# Output: 321

class Solution:
    def reverse(self, x: int) -> int:
        flag = 1
        if x < 0:
            flag = -1
        x = abs(x)
        save = []
        k = 1
        while x >= k:
            digit = (x//k) % 10
            save.append(digit)
            k = k * 10
        ans = 0
        while save:
            i = save[0]
            del save[0]
            ans = ans * 10 + i
        ans = ans * flag
        if ans <= - (2 ** 31) or ans > ( 2 ** 31 - 1):
            return 0
        return ans
