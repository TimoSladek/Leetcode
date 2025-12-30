class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), maxi = 1;
        string ans = s.substr(0, 1);
        for (int i = 1; i < n; ++i) {
            int l = i - 1, r = i + 1, count = 1;
            while (l >= 0 && r < n) {
                if (s[l] != s[r]) {
                    break;
                } else {
                    count += 2;
                    l--;
                    r++;
                }
            }
            if (count > maxi) {
                maxi = count;
                ans = s.substr(l+1, r-l-1);;
            }
        }
        for (int i = 1; i < n; ++i) {
            int l = i-1, r = i, count = 0;
            while (l >= 0 && r < n) {
                if (s[l] != s[r]) {
                    break;
                } else {
                    count += 2;
                    l--;
                    r++;
                }
            }
            if (count > maxi) {
                maxi = count;
                ans = s.substr(l+1, r-l-1);
            }
        }
        return ans;
    }
};