class Solution {
public:
    void f(int n, string digits, map<char, vector<char>> mpp, string &comb, vector<string> &result) {
        if (n == digits.size()) {
            result.push_back(comb);
            return;
        }
        for (char c : mpp[digits[n]]) {
            comb.push_back(c);
            f(n+1, digits, mpp, comb, result);
            comb.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        map<char,vector<char>> mpp;
        vector<string> result;
        string comb;
        mpp['2'] = {'a','b','c'};
        mpp['3'] = {'d','e','f'};
        mpp['4'] = {'g','h','i'};
        mpp['5'] = {'j','k','l'};
        mpp['6'] = {'m','n','o'};
        mpp['7'] = {'p','q','r', 's'};
        mpp['8'] = {'t','u','v'};
        mpp['9'] = {'w','x','y','z'};
        f(0, digits, mpp, comb, result);
        return result;
    }
};