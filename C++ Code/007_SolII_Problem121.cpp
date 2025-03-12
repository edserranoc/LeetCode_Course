// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int rLowD = 0, rMaxD = 0;
        int lowD = 0, maxD = 0;

        for(int cDay = 0; cDay<prices.size(); cDay++){
            if( prices[cDay] < prices[lowD] ){      // if current day is a better day to buy
                lowD = cDay; 
                maxD = cDay;                       // we change the buy day
            } 
            else if(prices[cDay] > prices[maxD]){  // if current day is a better day to sell  
                maxD = cDay;                       // we sell
            }

            if( prices[maxD] - prices[lowD] > prices[rMaxD] - prices[rLowD] ){ // if we find a pair of buy-sell days that give us a better profit
                rLowD = lowD; rMaxD = maxD;                                     // we change the decision
            }

        }

        return  prices[rMaxD] - prices[rLowD];
    }
};
