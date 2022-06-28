# https://leetcode.com/problems/count-primes/

class Solution:
    def countPrimes(self, n: int) -> int:
        if n == 0 or n == 1:
            return 0
        prime = [True] * n
        prime[0] = False
        prime[1] = False
        p = 2
        while p ** 2 <= n:
            if prime[p] == True:
                for i in range(p * 2, n, p):
                    prime[i] = False
            p += 1
        return sum(prime)
        
