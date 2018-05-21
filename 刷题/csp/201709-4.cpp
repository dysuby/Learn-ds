#include <iostream>
#include <vector>
using namespace std;

int matrix[1024][1024];
vector<int> graph[1024];
int n, m;

  void dfs(int i, int visited[], int start) {
    visited[i] = 1;
    matrix[i][start] = matrix[start][i] = 1;
    for (int j = 0; j < graph[i].size(); ++j) {
      if (visited[graph[i][j]] == 0)
        dfs(graph[i][j], visited, start);
    }
}

int main() {
  int s, e;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> s >> e;
    matrix[s][e] = 1;
    graph[s].push_back(e);
  }
  for (int i = 1; i <= n; ++i) {
    int visited[1024] = {0};
    dfs(i, visited, i);
  }
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    int flag = 1;
    for (int j = 1; j <= n; ++j)
      if (matrix[i][j] == 0)
        flag = 0;
    sum += flag;
  }
  cout << sum;
  return 0;
}