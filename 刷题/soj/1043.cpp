#include <iostream>
#include <vector>
using namespace std;

void getNext(vector<int> &codes, vector<int> &next) {
  int j = 0;
  for (int i = 1; i < codes.size(); ++i) {
    while (j > 0 && codes[j] != codes[i]) j = next[j];
    if (codes[j] == codes[i]) ++j;
    next[i + 1] = j;
  }
  return ;
}

int main() {
  int n, m;
  while (cin && cin >> n) {
    vector<int> codes(n), next(n + 1, 0);
    for (int i = 0; i < n; ++i) cin >> codes[i];
    cin >> m;
    vector<int> seq(m);
    for (int i = 0; i < m; ++i) cin >> seq[i];
    getNext(codes, next);
    int j = 0;
    for (int i = 0; i < m; ++i) {
      while (j > 0 && codes[j] != seq[i]) j = next[j];
      if (codes[j] == seq[i]) ++j;
      if (j == n) {
        cout << i - n + 1 << endl;
        break;
      }
    }
    if (j != n) cout << "no solution" << endl;
  }
  return 0;
}