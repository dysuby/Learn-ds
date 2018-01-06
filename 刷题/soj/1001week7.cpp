#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool cmp(const string &a, const string &b) { return a + b < b + a; }

int main() {
  int n, m;
  cin >> n;
  while (n--) {
    cin >> m;
    vector<string> s(m);
    for (int i = 0; i < m; ++i) cin >> s[i];
    sort(s.begin(), s.end(), cmp);
    for (int i = 0; i < m; ++i)
      cout << s[i];
    cout << endl;
  }
  return 0;
}