class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), l = 0;
        vector<bool> dp(n+1, false);
        vector<bool> cur(n+1, false);
        dp[0] = true;
        for (int i = 0;i <= n; ++i) {
            
        }
        return dp[n][m];
    }
};