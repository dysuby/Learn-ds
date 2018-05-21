#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int n, m, a, b;
  cin >> n >> m;
  vector<list<int> > graph(n + 1);
  vector<int> visited(n + 1, 0), degree(n + 1, 0);
  while (m--) {
    cin >> a >> b;
    graph[b].push_back(a);
    ++degree[a];
  }
  queue<int> q;
  int ans = 0, money = 100, left = n;
  for (int i = 1; i <= n; ++i) {
    if (!degree[i]) {
      q.push(i);
      visited[i] = 1;
    }
  }
  if (q.empty()) {
    cout << "Poor Xed" << endl;
    return 0;
  }
  while (q.size()) {
    int size = q.size(), top;
    while (size--) {
      top = q.front();
      --left;
      q.pop();
      ans += money;
      for (auto i : graph[top]) {
        --degree[i];
        if (!visited[i] && !degree[i]) {
          q.push(i);
          visited[i] = 1;
        }
      }
    }
    ++money;
  }
  if (left)
    cout << "Poor Xed\n";
  else
    cout << ans << endl;
  return 0;
}
