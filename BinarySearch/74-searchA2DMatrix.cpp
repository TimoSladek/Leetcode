class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n*m-1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int num = matrix[mid/m][mid%m];
            if (num == target) {
                return true;
            } else if(num < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};