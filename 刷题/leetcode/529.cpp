class Solution {
 public:
  int ok(vector<vector<char>>& board, int m, int n) {
    int mines = 0;
    if (m > 0 && board[m - 1][n] == 'M') ++mines;
    if (m < board.size() - 1 && board[m + 1][n] == 'M') ++mines;
    if (n > 0 && board[m][n - 1] == 'M') ++mines;
    if (n < board[0].size() - 1 && board[m][n + 1] == 'M') ++mines;
    if (n > 0 && m < board.size() - 1 && board[m + 1][n - 1] == 'M') ++mines;
    if (n < board[0].size() - 1 && m > 0 && board[m - 1][n + 1] == 'M') ++mines;
    if (n > 0 && m > 0 && board[m - 1][n - 1] == 'M') ++mines;
    if (n < board[0].size() - 1 && m < board.size() - 1 &&
        board[m + 1][n + 1] == 'M')
      ++mines;
    return mines;
  }
  void color(vector<vector<char>>& board, int m, int n) {
    if (m < 0 || m == board.size() || n < 0 || n == board[0].size() ||
        board[m][n] != 'E')
      return;
    int mines = ok(board, m, n);
    if (mines == 0) {
      board[m][n] = 'B';
      color(board, m + 1, n);
      color(board, m - 1, n);
      color(board, m + 1, n + 1);
      color(board, m + 1, n - 1);
      color(board, m, n + 1);
      color(board, m, n - 1);
      color(board, m - 1, n + 1);
      color(board, m - 1, n - 1);
    } else {
      board[m][n] = mines + '0';
    }
  }
  vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                   vector<int>& click) {
    int m = click[0], n = click[1];
    if (board[m][n] == 'M') {
      board[m][n] = 'X';
      return board;
    }
    color(board, m, n);
    return board;
  }
};