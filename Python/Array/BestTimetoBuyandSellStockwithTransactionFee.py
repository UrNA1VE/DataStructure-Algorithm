# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        flag = 0 # 0 means buy 1 means sell
        i = 0
        res = 0
        while i < len(prices):
            if flag == 0:
                buy = i
                i += 1
                while i < len(prices) and prices[i] <= prices[buy] + fee :
                    if prices[i] <= prices[buy]:
                        buy = i
                    i += 1
                flag = 1
            elif flag == 1:
                sell = prices[i]
                while i < len(prices) - 1 and sell - fee - prices[i + 1] <= 0:
                    sell = max(sell, prices[i + 1])
                    i += 1
                res += sell - prices[buy] - fee
                i += 1
                flag = 0
        return res
