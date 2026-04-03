class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyDay = 0;
        int maxProf = 0;
        for(int i = 1 ; i < prices.size() ; i++) {
            if(prices[i] > prices[buyDay]) {
                maxProf = max(maxProf, prices[i] - prices[buyDay]); 
            }
            else {
                buyDay = i;
            }
        }
        return maxProf;
    }
};
