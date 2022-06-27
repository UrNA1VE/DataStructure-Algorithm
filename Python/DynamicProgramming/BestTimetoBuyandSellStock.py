# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        maxprofit = 0
        buyprice = prices[0]
        profit = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                profit = max(prices[i] - buyprice, profit)
            if prices[i] < buyprice:
                maxprofit = max(profit, maxprofit)
                buyprice = prices[i]
                profit = 0
        maxprofit = max(profit, maxprofit)
        return maxprofit
