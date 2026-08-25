class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyDay = 0, maxProfit = 0;
        for(int i = 1 ; i < prices.size() ; i++) {
            if(prices[i] < prices[buyDay]) {
                buyDay = i;
            }
            else {
                maxProfit = max(maxProfit, prices[i] - prices[buyDay]);
            }
        }
        return maxProfit;
    }
};
