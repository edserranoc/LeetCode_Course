# 122. Best Time to Buy and Sell Stock II
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxProf = 0

        for cDay in range(1, len(prices)):
            # we buy evary day and sell ar the next one if there's a profit
            if(prices[cDay] > prices[cDay - 1]):
                maxProf += prices[cDay] - prices[cDay-1]
            # if not, we continue try again at the next one (we dont buy if not)
        
        return maxProf
