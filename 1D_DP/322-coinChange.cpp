class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> curr(amount+1, 1e9), prev(amount+1, 1e9);
        prev[0] = 0;
        for (int target = 1;target <= amount; ++target) {
            if (target % coins[0] == 0) {
                prev[target] = target / coins[0];
            }
        }
        for (int idx = 1;idx < n; ++idx) {
            for (int target = 0;target <= amount; ++target) {
                int take = 1e9;
                if (coins[idx] <= target) take = 1 + curr[target-coins[idx]];
                int notTake = prev[target];
                curr[target] = min(take, notTake);
            }
            prev = curr;
        }
        return prev[amount] >= 1e9 ? -1 : prev[amount];
    }
};