#include <iostream>
#include <set>
using namespace std;

bool cmp(const int &a, const int &b) { return a > b; }

int main() {
  int n, m, num;
  while (cin >> n >> m) {
    multiset<int, bool (*)(const int &, const int &)> s(&cmp);
    while (n--) {
      cin >> num;
      s.insert(num);
    }
    auto i = s.begin();
    cout << *i;
    while (--m) cout << " " << *(++i);
    cout << endl;
  }
  return 0;
}