void dfs(vector<vector<int>>& g, vector<bool>& visited, int& left, int index) {
  visited[index] = true;
  --left;
  for (int i = 0; i < g.size(); ++i)
    if (g[index][i] && !visited[i]) dfs(g, visited, left, i);
}

class Solution {
 public:
  int findCircleNum(vector<vector<int>>& M) {
    int size = M.size();
    if (!size) return 0;
    vector<bool> visited(size, 0);
    int left = size, ans = 0;
    while (left) {
      int index = 0;
      while (visited[index]) ++index;
      dfs(M, visited, left, index);
      ++ans;
    }
    return ans;
  }
};