#include <climits>
#include <cstring>
#include <iostream>
using namespace std;

int bar[1024];

int main() {
  int n, max, min, num, total;
  while (cin >> n) {
    memset(bar, 0, sizeof(int) * 1024);
    max = INT_MIN;
    min = INT_MAX;
    total = 0;
    for (int i = 0; i < n; ++i) {
      cin >> num;
      if (!bar[num]) ++total;
      ++bar[num];
      max = num > max ? num : max;
      min = num < min ? num : min;
    }
    cout << total << endl;
    cout << min;
    for (int i = min + 1; i <= max; ++i)
      if (bar[i]) cout << " " << i;
    cout << endl;
  }
  return 0;
}