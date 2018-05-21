#include <iostream>
using namespace std;
bool Prime[200000];

int main() {
  int n, i;
  cin >> n;
  Prime[0] = 1;
  Prime[1] = 1;
  for (i = 2; n; ++i) {
    if (!Prime[i]) --n;
    for (int j = 2; j * i < 200000; ++j) Prime[j * i] = 1;
  }
  cout << i - 1 << endl;
  return 0;
}