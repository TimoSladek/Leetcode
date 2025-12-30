class Solution {
public:
    int countNeighbours(vector<vector<int>> &copyOfBoard, int i, int j) {
        return copyOfBoard[i-1][j-1] + copyOfBoard[i-1][j] + copyOfBoard[i-1][j+1] +
                copyOfBoard[i+1][j-1] + copyOfBoard[i+1][j] + copyOfBoard[i+1][j+1] +
                copyOfBoard[i][j-1] + copyOfBoard[i][j+1];
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> copyOfBoard(n+2, vector<int>(m+2, 0));
        for (int i = 0;i < n; ++i) {
            for (int j = 0;j < m; ++j) {
                copyOfBoard[i+1][j+1] = board[i][j];
            }
        }
        for (int i = 0;i < n; ++i) {
            for (int j = 0;j < m; ++j) {
                int neighbours = countNeighbours(copyOfBoard, i+1, j+1);
                if (board[i][j]) {
                    if (neighbours < 2 || neighbours > 3) board[i][j] = 0;
                } else {
                    if (neighbours == 3) board[i][j] = 1;
                }
            }
        }
    }
};