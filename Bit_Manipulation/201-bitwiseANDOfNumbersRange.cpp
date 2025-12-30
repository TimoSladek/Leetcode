class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left != right) {
            if (left > right) left = left & left-1;
            else right = right & right-1;
        }
        return left;
    }
};