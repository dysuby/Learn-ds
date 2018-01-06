#include <iostream>
#include <vector>
using namespace std;

int find(int &a, vector<int> &set) {
  int ans = a;
  while (set[ans] != ans) ans = set[ans];
  return ans;
}

void join(int &a, int &b, vector<int> &set) {
  int ap = find(a, set), bp = find(b, set);
  if (ap != bp) set[bp] = ap;
}

int main() {
  int n, m, a, b;
  cin >> n >> m;
  vector<int> set(n + 1, 0);
  for (int i = 1; i <= n; ++i) set[i] = i;
  while (m--) {
    cin >> a >> b;
    join(a, b, set);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans += set[i] == i;
  cout << ans << endl;
  return 0;
}