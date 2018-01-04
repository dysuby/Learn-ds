#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void dij(vector<vector<int>> graph, vector<int> &path, int s) {
  int size = graph.size(), min = 0;
  vector<int> unvisited(size, 1);
  unvisited[s] = 0;
  for (int i = 0; i < size; ++i)
    if (graph[s][i] != INT_MAX) path[i] = graph[s][i];
  for (int i = 1; i < size; ++i) {
    min = -1;
    for (int i = 0; i < size; ++i) {
      if (unvisited[i]) {
        if (min == -1) min = i;
        min = path[min] < path[i] ? min : i;
      }
    }
    if (path[min] == INT_MAX) break;
    unvisited[min] = 0;
    for (int i = 0; i < size; ++i) {
      if (graph[min][i] != INT_MAX &&
          (graph[min][i] + path[min] < path[i] || path[i] == INT_MAX))
        path[i] = graph[min][i] + path[min];
    }
  }
}

int main() {
  int n, m, s, e, w;
  while (cin && cin >> n >> m) {
    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
    while (m--) {
      cin >> s >> e >> w;
      graph[s][e] = graph[s][e] < w ? graph[s][e] : w;
      graph[e][s] = graph[s][e];
    }
    cin >> s >> e;
    vector<int> path(n, INT_MAX);
    path[s] = 0;
    dij(graph, path, s);
    cout << (path[e] == INT_MAX ? -1 : path[e]) << endl;
  }
  return 0;
}