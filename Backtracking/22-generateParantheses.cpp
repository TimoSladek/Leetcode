class Solution {
public:
    void generate(int n, int m, string par, vector<string> &ans) {
        if (n == 0 && m == 0) {
            ans.push_back(par);
            return;
        }
        if (n > 0) {
            par += "(";
            generate(n-1, m, par, ans);
            par.pop_back();
        }
        if (m > 0 && m > n) {
            par += ")";
            generate(n, m-1, par, ans);
            par.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, n, "", ans);
        return ans;
    }
};