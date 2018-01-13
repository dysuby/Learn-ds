#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n;
  while (n--) {
    cin >> m;
    vector<vector<int> > graph(m, vector<int>(m));
    vector<int> degree(m, 0);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> graph[i][j];
        degree[i] += graph[i][j];
      }
    }
    make_heap(degree.begin(), degree.end());
    while (degree.size()) {
      cout << degree[0] << " ";
      pop_heap(degree.begin(), degree.end());
      degree.pop_back();
    }
    cout << endl;
  }
  return 0;
}