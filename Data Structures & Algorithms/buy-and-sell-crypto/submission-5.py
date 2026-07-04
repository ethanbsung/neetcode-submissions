class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mini = prices[0]
        maxi = 0

        for p in prices:
            if p < mini:
                mini = p
            profit = p - mini
            maxi = max(maxi, profit)

        return maxi
