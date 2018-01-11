/*the same as 1034.cpp*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct fuck {
  int col;
  int index;
  fuck() : col(-1), index(-1) {}
};

bool cmp(const fuck& a, const fuck& b) { return a.index > b.index; }

int main() {
  int col, n, e;
  while (cin >> col >> n) {
    vector<fuck> ope(col + 2);
    for (int i = 0; i < n; ++i) {
      cin >> e;
      ope[e].col = e;
      ope[e].index = i;
    }
    // cout << ope[0].index;
    sort(ope.begin(), ope.end(), cmp);
    int i = 0;
    while (ope[i].index != -1) ++i;
    cout << i-- << endl;
    cout << ope[i--].col;
    for (; i >= 0; --i) cout << ' ' << ope[i].col;
    cout << endl;
  }
  return 0;
}