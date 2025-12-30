class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, buy = prices[0];
        for (int i = 0; i < prices.size()-1; ++i) {
            if (prices[i+1] < prices[i]) {
                profit += prices[i] - buy;
                buy = prices[i+1];
            } else if (i == prices.size()-2) {
                profit += prices[i+1] - buy;
            }
        }
        return profit;
    }
};