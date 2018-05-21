class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    int index[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
    map<char, int> m[3][3], row[9], col[9];
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board.size(); ++j) {
        if (board[i][j] == '.') continue;
        if (++m[index[i]][index[j]][board[i][j]] == 2) return false;
        if (++row[i][board[i][j]] == 2) return false;
        if (++col[j][board[i][j]] == 2) return false;
      }
    }
    return true;
  }
};