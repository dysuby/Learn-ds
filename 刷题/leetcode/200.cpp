class Solution {
 public:
  void expand(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& visited) {

    // queue<pair<int, int>> q;
    int rowSize = grid.size(), colSize = grid[0].size();
    // q.push(make_pair(i, j));
    // while (q.size()) {
      // int row = q.front().first, col = q.front().second;
      // cout << row << " " << col << endl;
      // q.pop();
      visited[row][col] = true;
      for (int x = -1; x <= 1; x += 2) {
        int nr = row + x, nc = col + x;
        // cout << nr << " " << nc << endl;
        if (nr >= 0 && nr < rowSize && !visited[nr][col] &&
            grid[nr][col] == '1')
          // q.push(make_pair(nr, col));
          expand(grid, nr, col, visited);
        if (nc >= 0 && nc < colSize && !visited[row][nc] &&
            grid[row][nc] == '1')
          // q.push(make_pair(row, nc));
          expand(grid, row, nc, visited);
      }
    // }
  }
  int numIslands(vector<vector<char>>& grid) {
    int rowSize = grid.size();
    if (!rowSize) return 0;
    int colSize = grid[0].size();
    if (!colSize) return 0;
    vector<vector<bool>> visited(rowSize, vector<bool>(colSize, false));
    int num = 0;
    // cout << rowSize << " " << colSize << endl;
    for (int i = 0; i < rowSize; ++i) {
      for (int j = 0; j < colSize; ++j) {
        if (!visited[i][j] && grid[i][j] == '1') {
          expand(grid, i, j, visited);
          ++num;
          // cout << endl;
        }
      }
    }
    return num;
  }
};