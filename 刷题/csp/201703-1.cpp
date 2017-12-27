#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int total = 0, now = 0, temp;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    now += temp;
    if (now >= k) {
      ++total;
      now = 0;
    }
  }
  if (now) ++total;
  cout << total;
  return 0;
}