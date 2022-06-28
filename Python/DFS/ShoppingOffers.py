# https://leetcode.com/problems/shopping-offers/

import numpy as np
class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        ret = float("inf")
        n = len(price)
        m = len(special)
        curr = [0 for i in range(n)]
        def dfs(idx, spe_money, curr):
            nonlocal ret
            for j in range(n):
                if curr[j] > needs[j]:
                    return
            add = sum(np.multiply(np.subtract(needs, curr), price))
            money = spe_money + add
            ret = min(ret, money)
            
            for i in range(idx, m):
                spe_money += special[i][n]
                dfs(i, spe_money, np.add(curr, special[i][0:n]))
                spe_money -= special[i][n]
            return
        dfs(0, 0, curr)
        return ret
