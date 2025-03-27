# 121. Best Time to Buy and Sell Stock
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxProf = 0
        bCost = prices[0]

        for cDay in range(len(prices)):
            if(prices[cDay] < bCost):
                bCost = prices[cDay]
            if(prices[cDay] - bCost > maxProf ): 
                maxProf = prices[cDay] - bCost
        
        return maxProf
