#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t, n, num, flag = 0;
  cin >> t;

  while (t--) {
    if (flag++) cout << endl;
    cin >> n;
    vector<vector<int> > graph(n, vector<int>(n, 0));
    vector<int> dis(n, INT_MAX), visited(n, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> graph[i][j];
        if (!graph[i][j]) graph[i][j] = INT_MAX;
      }
    }

    int s = 0, left = n - 1, ans = INT_MIN, smaller = -1;

    visited[s] = 1;
    for (int i = 0; i < n; ++i) {
      if (visited[i]) continue;
      if (smaller == -1) smaller = i;
      dis[i] = min(dis[i], graph[s][i]);
      smaller = dis[i] < dis[smaller] ? i : smaller;
    }

    while (left) {
      visited[smaller] = 1;
      --left;
      ans = max(dis[smaller], ans);
      int nsmaller = -1;
      for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
          dis[i] = min(graph[smaller][i], dis[i]);
          if (nsmaller == -1) nsmaller = i;
          nsmaller = dis[i] < dis[nsmaller] ? i : nsmaller;
        }
      }
      smaller = nsmaller;
    }
    
    cout << ans << endl;
  }

  return 0;
}