#include <iostream>
#include <map>
using namespace std;

int main() {
  int n, c = 0;
  long long num;
  while (cin >> n) {
    if (c++ != 0) cout << endl;
    map<long long, int> m;
    while (n--) {
      cin >> num;
      if (m.find(num) == m.end())
        m[num] = 1;
      else
        ++m[num];
    }
    for (auto i : m) cout << i.first << ' ' << i.second << '\n';
    // cout << endl;
  }
  return 0;
}