// #include <iostream>
// #include <vector>
// using namespace std;

// void dfs(int a, int b, int l, vector<vector<int> > graph, vector<int> &visited,
//          int &ans) {
//   if (b == a && l == 1) {
//     ++ans;
//     return;
//   } else if (l == 1)
//     return;
//   visited[a] = 1;
//   for (auto i : graph[a])
//     if (!visited[i]) dfs(i, b, l - 1, graph, visited, ans);
// }

// int main() {
//   int n, m, l, a, b, q;
//   cin >> n >> m >> l;
//   vector<vector<int> > graph(n + 1);
//   for (int i = 0; i < m; ++i) {
//     cin >> a >> b;
//     graph[a].push_back(b);
//   }
//   cin >> q;
//   while (q--) {
//     vector<int> visited(n + 1, 0);
//     cin >> a >> b;
//     int ans = 0;
//     dfs(a, b, l, graph, visited, ans);
//     cout << ans << endl;
//   }
//   return 0;
// }