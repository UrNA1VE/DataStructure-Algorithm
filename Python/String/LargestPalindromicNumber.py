# https://leetcode.com/problems/largest-palindromic-number/

class Solution:
    def largestPalindromic(self, num: str) -> str:
        cnt = Counter(num)
        left = ''.join(cnt[i]//2 * i for i in "9876543210").lstrip("0")
        mid = max(cnt[i]%2 * i for i in cnt)
        
        return left + mid + left[::-1] or "0"
        
