#include <iostream>
using namespace std;

int main() {
  int n, m, max = 0;
  cin >> n >> m;
  for (int i = n; i <= m; ++i) {
    int temp = i, ans = 1;
    while (temp != 1) {
      if (temp & 1) temp = 3 * temp + 1;
      else temp /= 2;
      ++ans;
    }
    max = max > ans ? max : ans;
  }
  cout << max << endl;
  return 0;
}