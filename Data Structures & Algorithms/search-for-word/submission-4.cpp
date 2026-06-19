class Solution {
public:
    bool ex(vector<vector<char>>& board, string word, int i, int row, int col) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
            return false;
        }
        char temp = board[row][col];
        if (temp != word[i]) {
            return false;
        }
        if (i == word.size() - 1) {
            return true;
        }
        board[row][col] = '/';
        if (ex(board, word, i+1, row+1, col)
            || ex(board, word, i+1, row, col+1)
            || ex(board, word, i+1, row-1, col)
            || ex(board, word, i+1, row, col-1)) {
            return true;
        }
        board[row][col] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (ex(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
