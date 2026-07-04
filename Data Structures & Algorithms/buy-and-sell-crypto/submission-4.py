class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lowest = prices[0]
        maxProfit = 0

        for i in range(1, len(prices), 1):
            if prices[i] < lowest:
                lowest = prices[i]
            profit = prices[i] - lowest
            maxProfit = max(maxProfit, profit)

        return maxProfit