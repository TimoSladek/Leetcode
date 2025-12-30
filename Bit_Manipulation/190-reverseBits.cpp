class Solution {
public:
    string toReversedBits(int n) {
        string s = "";
        while (n > 1) {
            if (n & 1) s += '1';
            else s += '0';
            n /= 2;
        }
        if (n & 1) s += '1';
        else s += '0';
        for (int i = s.size();i < 32; ++i) {
            s += '0';
        }
        return s;
    }
    int toNum(string s) {
        int res = 0;
        long long power2 = 1;
        for (int i = s.size()-1;i >= 0; --i) {
            if (s[i] == '1') res += power2;
            power2 = power2 * 2;
        }
        return res;
    }
    int reverseBits(int n) {
        string s = toReversedBits(n);
        return toNum(s);
    }
};