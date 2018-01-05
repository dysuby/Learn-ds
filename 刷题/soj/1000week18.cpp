#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &q, vector<int> c, int node, int total,
         int target) {
  if (!target) {
    q.push_back(c);
    return;
  }
  if (node > total) return;
  c[node] = 1;
  dfs(q, c, node + 1, total, target - 1);
  c[node] = 0;
  dfs(q, c, node + 1, total, target);
}

double tree(vector<int> sol, vector<vector<int>> graph, vector<int> nodes) {
  int edge = 0, node = 0, size = sol.size(), root;
  vector<int> known(size, 1), dis(size, INT_MAX), pre(size, 0);
  for (int i = 1; i < size; ++i) {
    if (sol[i]) {
      root = i;
      node += nodes[i];
      known[i] = 0;
    }
  }
  dis[root] = 0;
  known[root] = 1;
  for (int i = 1; i < size; ++i) {
    if (sol[i] && graph[root][i]) {
      dis[i] = graph[root][i];
      pre[i] = root;
    }
  }
  while (true) {
    int min = 0;
    for (int i = 1; i < size; ++i) {
      // cout << i << " " << known[i] << " " << sol[i] << " " << dis[i] << endl;
      if (sol[i] && !known[i]) min = dis[i] < dis[min] ? i : min;
    }
    if (!min) break;
    known[min] = 1;
    edge += graph[pre[min]][min];
    for (int i = 1; i < size; ++i) {
      if (sol[i] && !known[i] && graph[min][i] < dis[i]) {
        dis[i] = graph[min][i];
        pre[i] = min;
      }
    }
  }
  // cout << (double)edge / node << endl;
  return (double)edge / node;
}

int main() {
  int n, m, ans;
  cin >> n >> m;
  while (n || m) {
    ans = 0;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1));
    vector<int> nodes(n + 1);
    for (int i = 1; i <= n; ++i) cin >> nodes[i];
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) cin >> graph[i][j];
    vector<vector<int>> q;
    dfs(q, vector<int>(n + 1, 0), 1, n, m);
    int size = q.size();
    vector<double> ratio;
    for (int i = 0; i < size; ++i) {
      ratio.push_back(tree(q[i], graph, nodes));
      ans = ratio[ans] <= ratio.back() ? ans : i;
    }
    int i = 0;
    for (; i <= n; ++i) {
      if (q[ans][i]) {
        cout << i;
        break;
      }
    }
    for (++i; i <= n; ++i)
      if (q[ans][i]) cout << " " << i;
    cin >> n >> m;
    // if (!n && !m) break;
    cout << '\n';
  }
  return 0;
}