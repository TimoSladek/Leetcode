class Solution {
public:
    bool isValid(int i, int j, vector<int> &upDiag, vector<int> &downDiag, vector<string> &board) {
        if (downDiag[i+j] == 1 || upDiag[board.size() + i - j] == 1) return false;
        for(int k = 0;k < j; ++k) {
            if (board[i][k] == 'Q') {
                return false;
            }
        }
        return true;
    }

    int nQueens(int idx, vector<int> &upDiag, vector<int> &downDiag, vector<string> &board) {
        if (idx == board.size()) return 1;
        int ans = 0;
        for (int i = 0;i < board.size(); ++i) {
            if (isValid(i, idx, upDiag, downDiag, board)) {
                board[i][idx] = 'Q';
                downDiag[i+idx] = 1;
                upDiag[board.size() + i - idx] = 1;
                ans += nQueens(idx+1, upDiag, downDiag, board);
                downDiag[i+idx] = 0;
                upDiag[board.size() + i - idx] = 0;
                board[i][idx] = '.';
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
        vector<string> board;
        string row;
        vector<int> upDiag(2*n, 0), downDiag(2*n, 0);
        for (int i = 0;i < n; ++i) {
            row += ".";
        }
        for (int i = 0;i < n; ++i) {
            board.push_back(row);
        }
        return nQueens(0, upDiag, downDiag, board);
    }
};