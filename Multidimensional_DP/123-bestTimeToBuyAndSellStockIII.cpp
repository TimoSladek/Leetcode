class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(5, 0), after(5, 0);
        for (int i = n-1;i >= 0; --i) {
            for (int transaction = 3;transaction >= 0; --transaction) {
                if (transaction % 2 == 0) {
                    int buy = -prices[i] + after[transaction+1];
                    int nothing = after[transaction];
                    curr[transaction] = max(buy, nothing);
                } else {
                    int sell = prices[i] + after[transaction+1];
                    int nothing = after[transaction];
                    curr[transaction] = max(sell, nothing);
                }
            }
            after = curr;
        }
        return after[0];
    }
};