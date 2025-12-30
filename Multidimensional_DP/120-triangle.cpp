class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), ans = INT_MAX;
        vector<int> dp(n);
        dp[0] = triangle[0][0];
        for (int i = 1;i < n; ++i) {
            vector<int> temp(n);
            for (int j = 0;j < i+1; ++j) {
                int up = INT_MAX, upLeft = INT_MAX;
                if(j < i) up = dp[j] + triangle[i][j];
                if (j > 0) upLeft = dp[j-1] + triangle[i][j];
                temp[j] = (min(up, upLeft));
            }
            dp = temp;
        }
        for (int i = 0;i < n; ++i) {
            ans = min(ans, dp[i]);
        }
        return ans;
    }
};