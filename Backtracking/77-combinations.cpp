class Solution {
public:
    void f(int k, int n, vector<int> &comb, vector<vector<int>> &result, int j) {
        if (k == 0) {
            result.push_back(comb);
            return;
        }
        for (int i = j+1; i <= n; ++i) {
            comb.push_back(i);
            f(k-1, n, comb, result, i);
            comb.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> comb;
        f(k, n, comb, result, 0);
        return result;
    }
};