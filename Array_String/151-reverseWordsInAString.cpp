class Solution {
public:
    string reverseWords(string s) {
        string ans = "", word = "";
        for (int i = s.size()-1;i >= 0; --i) {
            if (s[i] == ' ') {
                if (word != "") {
                    reverse(word.begin(), word.end());
                    ans += word;
                    word.clear();
                    ans += ' ';
                }
            } else {
                word += s[i];
            }
        }
        if (word != "") {
            reverse(word.begin(), word.end());
            ans += word;
        } else {
            ans.pop_back();
        }
        return ans;
    }
};