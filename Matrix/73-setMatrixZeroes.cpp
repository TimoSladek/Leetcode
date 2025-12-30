class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> rows(n, 0), columns(m, 0);
        for (int i = 0;i < n; ++i) {
            for (int j = 0;j < m; ++j) {
                if (!matrix[i][j]) {
                    rows[i] = 1;
                    columns[j] = 1;
                }
            }
        }
        for (int i = 0;i < n; ++i) {
            for (int j = 0;j < m; ++j) {
                if (rows[i] || columns[j]) matrix[i][j] = 0;
            }
        }
    }
};