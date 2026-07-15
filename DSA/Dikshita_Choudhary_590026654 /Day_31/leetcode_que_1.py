class Solution:
    def finalPrices(self, prices):
        ans = prices[:]
        stack = []

        for i, price in enumerate(prices):
            while stack and prices[stack[-1]] >= price:
                ans[stack.pop()] -= price
            stack.append(i)

        return ans
