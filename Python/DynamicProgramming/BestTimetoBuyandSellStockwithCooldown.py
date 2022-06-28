# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        prebuy = -prices[0]
        prenothing = 0
        presell = 0
        n = len(prices)
        for i in range(1, n):
            buy = max(prebuy, prenothing - prices[i])
            nothing = max(prenothing, prebuy, presell)
            sell = max(prebuy + prices[i], presell)
            prebuy, prenothing, presell = buy, nothing, sell
        return max(prenothing, presell)
