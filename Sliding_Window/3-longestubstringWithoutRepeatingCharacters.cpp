class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), l = 0, ans = 0, cnt = 0;
        set<char> ms;
        for (int i = 0;i < n; ++i) {
            if (ms.count(s[i])) {
                ms.erase(s[i]);
                while (ms.count(s[l])) {
                    ms.erase(s[l]);
                    cnt--;
                    l++;
                }
                l++;
                ms.insert(s[i]);
            } else {
                ms.insert(s[i]);
                cnt++;
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};