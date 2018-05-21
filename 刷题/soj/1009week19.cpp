#include <iostream>
#include <queue>
using namespace std;

int graph[128][128];
int visited[128];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) cin >> graph[i][j];
  queue<int> q;
  q.push(m);
  visited[m] = 1;
  while (q.size()) {
    int top = q.front();
    q.pop();
    cout << top;
    for (int i = 1; i <= n; ++i) {
      if (graph[top][i] && !visited[i]) {
        q.push(i);
        visited[i] = 1;
      }
    }
    if (!q.empty()) cout << " ";
  }
  return 0;
}