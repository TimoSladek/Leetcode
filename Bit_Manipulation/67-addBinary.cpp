class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() > b.size()) return addBinary(b, a);
        string startingZeros = "";
        for (int i = a.size();i < b.size(); ++i) {
            startingZeros += '0';
        }
        string newA = startingZeros + a;
        string res = "";
        int carry = 0;
        for (int i = b.size()-1;i >= 0; --i) {
            if (newA[i] == b[i]) {
                if (b[i] == '1') {
                    if (carry) {
                        res += '1';
                    } else {
                        carry = 1;
                        res += '0';
                    }
                } else {
                    if (carry) {
                        res += '1';
                        carry = 0;
                    } else {
                        res += '0';
                    }
                }
            } else {
                if (carry) {
                    res += '0';
                } else {
                    res += '1';
                }
            }
        }
        if (carry) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};