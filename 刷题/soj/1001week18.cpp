#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// int dfs(int s, int e, int min, vector<vector<int>> graph,
//         vector<int> visited) {
//   if (s == e) return min;
//   int size = graph.size(), max = 0;
//   for (int i = 1; i < size; ++i) {
//     if (graph[s][i] && !visited[i]) {
//       visited[i] = 1;
//       min = min < graph[s][i] ? min : graph[s][i];
//       int m = dfs(i, e, min, graph, visited);
//       min = min < m ? min : m;
//       max = max > min ? max : min;
//     }
//   }
//   return max;
// }

// int sol(vector<vector<int>> &graph, int s, int e) {
//   int size = graph.size();
//   vector<int> path(size, 0), visited(size, 0);
//   path[s] = INT_MAX;
//   visited[s] = 0;
//   for (int i = 1; i < size; ++i) {
//     for (int j = )
//   }
// }

int main() {
  int t, n, r, s, e, each;
  cin >> t;
  while (t--) {
    cin >> n >> r;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i <= n; ++i) graph[i][i] = 0;
    for (int i = 0; i < r; ++i) {
      cin >> s >> e >> each;
      graph[s][e] = each;
      graph[e][s] = each;
    }
    cin >> s >> e >> each;
    for (int i = 1; i <= n; ++i) 
      for (int j = 1; j <= n; ++j)
        for (int k = 1; k <= n; ++k)
          graph[i][j] = max(graph[i][j], min(graph[i][k], graph[k][j]));
    // cout << graph[s][e] << endl;s
    cout << ceil((double)each / (graph[s][e] - 1)) << endl;
  }
  return 0;
}