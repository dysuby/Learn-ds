#include <iostream>
#include <vector>
using namespace std;

struct pos {
  int x, y;
  pos(int i, int j) : x(i), y(j) {}
};

bool findAns(int sx, int sy, int ex, int ey, vector<vector<char>> &maze,
             vector<pos> &ans) {
  ans.push_back(pos(sx, sy));
  maze[sx][sy] = '1';
  if (sx == ex && sy == ey) return true;
  if (sx > 0 && maze[sx - 1][sy] != '1' &&
          findAns(sx - 1, sy, ex, ey, maze, ans) ||
      sx < ex && maze[sx + 1][sy] != '1' &&
          findAns(sx + 1, sy, ex, ey, maze, ans) ||
      sy > 0 && maze[sx][sy - 1] != '1' &&
          findAns(sx, sy - 1, ex, ey, maze, ans) ||
      sy < ey && maze[sx][sy + 1] != '1' &&
          findAns(sx, sy + 1, ex, ey, maze, ans))
    return true;
  ans.pop_back();
  return false;
}

int main() {
  int n, row, col;
  cin >> n;
  while (n--) {
    cin >> row >> col;
    vector<vector<char>> maze(row, vector<char>(col));
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j) cin >> maze[i][j];
    vector<pos> ans;
    if (!findAns(0, 0, row - 1, col - 1, maze, ans)) {
      cout << "no" << endl;
      continue;
    }
    cout << "(" << ans[0].x << "," << ans[0].y << ")";
    for (int i = 1; i < ans.size(); ++i)
      cout << " (" << ans[i].x << "," << ans[i].y << ")";
    cout << endl;
  }
}