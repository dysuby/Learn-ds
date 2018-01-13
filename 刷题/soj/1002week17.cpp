#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

bool cmp(const int &a, const int &b) { return a > b; }

int main() {
  int t, n, m, a, b;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<list<int> > graph(n + 1);
    vector<int> degree(n + 1, 0), ans;
    priority_queue<int, vector<int>, bool (*)(const int &, const int &)> q(cmp);
    for (int i = 0; i < m; ++i) {
      cin >> a >> b;
      graph[a].push_back(b);
      ++degree[b];
    }
    for (int i = 1; i <= n; ++i)
      if (!degree[i]) q.push(i);
    while (q.size()) {
      int i = q.top();
      ans.push_back(i);
      q.pop();
      for (auto next : graph[i]) {
        --degree[next];
        if (!degree[next]) q.push(next);
      }
    }
    if (ans.size() != n) {
      cout << "there is a cycle\n";
    } else {
      for (auto i : ans) cout << i << " ";
      cout << endl;
    }
  }
  return 0;
}