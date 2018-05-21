#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
  int id, problem;
  while (scanf("%d%d", &id, &problem) != EOF)
    ++sum[id][problem];
  for (int i = 1; i <= n; ++i) {
    cout << sum[i][1];
    for (int j = 2; j <= m; ++j)
      cout << " " << sum[i][j];
    cout << endl;
  }
  return 0;
}