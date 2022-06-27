#https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        prebuy = 0 - prices[0]
        presell = 0
        prenothing = 0
        for i in range(1, len(prices)):
            buy = max(presell - prices[i], prebuy)
            sell = max(prebuy + prices[i], presell)
            nothing = max(presell, prebuy, prenothing)
            prebuy, presell, prenothing = buy, sell, nothing
        return max(prenothing, presell)
