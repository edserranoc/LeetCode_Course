# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
    int buy = prices[0], profit = 0;


    for(int i=1;i<prices.size();i++){
        if (prices[i]<buy){
            buy = prices[i];
        }else{
            profit += prices[i]-buy;
            buy = prices[i];
        }
    }
    return profit;
    }
};

int main(){
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}