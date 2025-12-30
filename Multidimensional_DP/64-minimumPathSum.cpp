class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dp(m);
        for (int i = 0;i < n; ++i) {
            vector<int> temp(m);
            for (int j = 0;j < m; ++j) {
                if (i == 0 && j == 0) {
                    temp[0] = grid[0][0];
                    continue;
                };
                int up = INT_MAX, left = INT_MAX;
                if (i > 0) up = dp[j] + grid[i][j];
                if (j > 0) left = temp[j-1] + grid[i][j];
                temp[j] = min(up, left);
            }
            dp = temp;
        }
        return dp[m-1];
    }
};