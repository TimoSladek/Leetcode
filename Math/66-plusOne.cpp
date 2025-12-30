class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool addN = true;
        for (int i = digits.size()-1;i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                addN = false;
                break;
            } else {
                digits[i] = 0;
            }
        }
        if (addN) {
            vector<int> newDigits;
            newDigits.push_back(1);
            for (int i = 0;i < digits.size(); ++i) {
                newDigits.push_back(digits[i]);
            }
            return newDigits;
        }
        return digits;
    }
};