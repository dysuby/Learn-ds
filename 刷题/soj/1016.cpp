#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(const int &a, const int &b) { return a > b; }

int main() {
  int n, size;
  cin >> n;
  while (n--) {
    cin >> size;
    vector<vector<int> > graph(size, vector<int>(size));
    vector<int> degree(size);
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j) cin >> graph[i][j];
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        if (graph[i][j]) {
          ++degree[i];
          ++degree[j];
          graph[i][j] = graph[j][i] = 0;
        }
      }
    }
    // sort(degree.begin(), degree.end(), cmp);
    for (int i = 0; i < size; ++i) cout << degree[i] << " ";
    cout << endl;
  }
  return 0;
}