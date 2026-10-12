class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        minPrice = prices[0]
        ans = 0
        for price in prices:
            ans = max(ans, price - minPrice)
            minPrice = min(minPrice, price)
        return ans