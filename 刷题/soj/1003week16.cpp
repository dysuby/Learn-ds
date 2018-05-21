#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int visited[101];

void dfs(vector<vector<int> > graph, int visited[], int s, int length,
         int &ans) {
  ans = max(ans, length);
  visited[s] = 1;
  int size = graph[s].size();
  for (int i = 0; i < size; ++i) {
    if (!visited[graph[s][i]])
      dfs(graph, visited, graph[s][i], length + 1, ans);
  }
}

int main() {
  int n, m, i, j, size, ans;
  cin >> n;
  while (n--) {
    cin >> m;
    ans = 0;
    size = 0;
    vector<vector<int> > graph(101);
    while (m--) {
      cin >> i >> j;
      graph[i].push_back(j);
      graph[j].push_back(i);
      size = max(size, max(i, j));
    }
    for (int i = 0; i <= size; ++i) {
      memset(visited, 0, sizeof(int) * 101);
      dfs(graph, visited, i, 0, ans);
    }
    cout << ans << endl;
  }
  return 0;
}