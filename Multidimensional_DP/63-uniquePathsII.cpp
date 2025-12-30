class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<int> dp(m);
        for (int i = 0;i < n; ++i) {
            vector<int> temp(m);
            for (int j = 0;j < m; ++j) {
                if (i == 0 && j == 0) {
                    temp[0] = (obstacleGrid[0][0] == 1) ? 0 : 1;
                    continue;
                }
                if (obstacleGrid[i][j] == 1){
                    temp[j] = 0;
                    continue;
                }
                int up = 0, left = 0;
                if (i > 0) up = dp[j];
                if (j > 0) left = temp[j-1];
                temp[j] = up + left;
            }
            dp = temp;
        }
        return dp[m-1];
    }
};