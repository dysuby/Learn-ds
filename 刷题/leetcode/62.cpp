class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (m == 1 || n == 1) return 1;
    vector<vector<int> > graph(m, vector<int>(n));
    for (int i = 0; i < m; ++i) graph[i][0] = 1;
    for (int i = 0; i < n; ++i) graph[0][i] = 1;
    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        graph[i][j] = graph[i - 1][j] + graph[i][j - 1];
    return graph[m - 1][n - 1];
  }
};