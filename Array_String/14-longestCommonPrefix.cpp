class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pref = strs[0];
        int n = pref.size();
        bool isPref;
        for (int i = 0;i < n; ++i) {
            isPref = true;
            for (int j = 1;j < strs.size(); ++j) {
                if (!strs[j].starts_with(pref)) {
                    isPref = false;
                    pref.pop_back();
                    break;
                }
            }
            if (isPref) return pref;

        }
        return pref;
    }
};