#include <algorithm>
#include <iostream>

using namespace std;

int a[120];

int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0, flag = true;
    for (int i = 0; i < n; ++i) {
      flag = true;
      for (int j = 0; j < n; ++j) {
        if ((a[i] - a[j]) * (i - j) < 0) {
          flag = false;
          break;
        }
      }
      if (flag) ++ans;
    }
    cout << ans << endl;
  }
  return 0;
}