class Solution {
public:
    bool checkSquare(int i, int j, set<char> &ms, vector<vector<char>>& board) {
        for (int k = 0;k < 9; ++k) {
            char c = board[3 * (i/3) + k/3][3 * (j/3) + k%3];
            if (c == '.') continue;
            if (ms.count(c) == 0) ms.insert(c);
            else return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> ms;
        //check rows
        for (int i = 0;i < 9; ++i) {
            for (int j = 0;j < 9; ++j) {
                if (board[i][j] == '.') continue;
                if (ms.count(board[i][j]) == 0) {
                    ms.insert(board[i][j]);
                } else {
                    return false;
                }
            }
            ms.clear();
            cout << ms.size();
        }
        //check columns
        for (int i = 0;i < 9; ++i) {
            for (int j = 0;j < 9; ++j) {
                if (board[j][i] == '.') continue;
                if (ms.count(board[j][i]) == 0) ms.insert(board[j][i]);
                else return false;
            }
            ms.clear();
        }
        //check 3x3 squares
        for (int i = 0;i < 9; i+=3) {
            for (int j = 0;j < 9; j+=3) {
                if (!checkSquare(i, j, ms, board)) return false;
                ms.clear();
            }
        }
        return true;
    }
};