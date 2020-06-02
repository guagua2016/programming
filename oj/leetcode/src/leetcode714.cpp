class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        vector<int> sold(prices.size(),0);
        vector<int> hold(prices.size(),0);

        hold[0] = -prices[0];
        for(int i=1;i<prices.size();i++){
            sold[i] = max(hold[i-1]+prices[i]-fee,sold[i-1]);
            hold[i] = max(sold[i-1]-prices[i],hold[i-1]);
        }
        return sold.back();
    }
};