class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currProfit = 0;
        for(int i = 0 ; i < prices.size() - 1 ; i++) {
            if(prices[i] < prices[i + 1]) {
                currProfit += (prices[i + 1] - prices[i]);
            }
        }
        return currProfit;
    }
};