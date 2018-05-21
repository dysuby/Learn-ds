//課程結束了，沒提交過

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int a[21];
int main() {
  int n, m, l = 0;
  cin >> n;
  while (n--) {
    cin >> m;
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      cin >> a[i];
      l = max(a[i], l);
    }
    vector<int> d((l + 1) * 2, 0);
    for (int i = 0; i < m; ++i) d[2 * a[i]] = 1;
    for (int i = 0; i < m; ++i)
      if (d[a[i]] == 1) ++ans;
    cout << ans << endl;
  }
  return 0;
}