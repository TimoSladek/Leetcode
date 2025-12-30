class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for (int i = 0;i < n; ++i) {
            if (haystack[i] == needle[0]) {
                bool gotNeedle = true;
                int j = 1;
                while (j < m) {
                    if (haystack[i + j] != needle[j]) {
                        gotNeedle = false;
                        break;
                    }
                    j++;
                }
                if (gotNeedle && j == m) return i;
            }
        }
        return -1;
    }
};