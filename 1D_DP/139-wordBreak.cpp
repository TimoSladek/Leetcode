class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        set<string> ms(wordDict.begin(), wordDict.end());
        dp[n] = 1;
        for (int i = n; i >= 0; --i) {
            for (int j = i+1;j <= n; ++j) {
                if (ms.count(s.substr(i, j-i))) {
                    if (dp[j]) dp[i] = true;
                }
            }
        }
        return dp[0];
    }
};