class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, bestBuy = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            profit = max(prices[i]-bestBuy, profit);
            bestBuy = min(bestBuy, prices[i]);
        }
        return profit;
    }
};