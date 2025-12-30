class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0, word = 1;
        for (int i = s.size()-1;i >= 0; --i) {
            if (s[i] != ' ') {
                cnt++;
                word = 0;
            } else if (s[i] == ' ' && word) {
                continue;
            } else {
                break;
            }
        }
        return cnt;
    }
};