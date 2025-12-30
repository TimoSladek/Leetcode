class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> curr(m+1, 0), prev(m+1, 0);
        for (int j = 1;j <= m; ++j) {
            prev[j] = j;
        }
        for (int i = 1;i <= n; ++i) {
            curr[0] = i;
            for (int j = 1;j <= m; ++j) {
                if (word1[i-1] == word2[j-1]) curr[j] = prev[j-1];
                else {
                    int re = 1 + prev[j-1];
                    int de = 1 + prev[j];
                    int in = 1 + curr[j-1];
                    curr[j] = min(re, min(de, in));
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};