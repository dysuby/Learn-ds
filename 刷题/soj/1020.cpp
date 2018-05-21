#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, a, b;
  cin >> n;
  while (n--) {
    vector<int> fuck(3);
    cin >> m;
    while (m--) {
      cin >> a >> b;
      fuck[a - 1] = b > fuck[a - 1] ? b : fuck[a - 1];
    }
    for (int i = 0; i < 3; ++i)
      if (fuck[i]) cout << i + 1 << " " << fuck[i] << endl;
  }
  return 0;
}