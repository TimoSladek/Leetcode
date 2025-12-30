class Solution {
public:
    bool f(int i, int j, vector<vector<int>> &visited, vector<vector<char>>& board,
        string word, string &mby, int di[], int dj[]) {
        if (word.size() == mby.size()) {
            if (mby == word) return true;
            return false;
        }
        for (int k = 0;k < 4; ++k) {
            int nextI = i + di[k];
            int nextJ = j + dj[k];
            if (nextI >= 0 && nextJ >= 0 && nextI < board.size() && nextJ < board[0].size() &&
                !visited[nextI][nextJ]) {
                visited[nextI][nextJ] = 1;
                mby.push_back(board[nextI][nextJ]);
                if (f(nextI, nextJ, visited, board, word, mby, di, dj)) return true;
                mby.pop_back();
                visited[nextI][nextJ] = 0;
                }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int di[] = {0, 1, 0, -1};
        int dj[] = {1, 0, -1, 0};
        if (word.size() > n*m) return false;
        string mby = "";
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0;i < n; ++i) {
            for (int j = 0;j < m; ++j) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = 1;
                    mby.push_back(board[i][j]);
                    if (f(i, j, visited, board, word, mby, di, dj)) return true;
                    mby.pop_back();
                    visited[i][j] = 0;
                }
            }
        }
        return false;
    }
};