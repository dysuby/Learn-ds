#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
  int n;
  string s;
  while (cin >> n && n) {
    set<string> balls;
    while (n--) {
      cin >> s;
      balls.insert(s);
    }
    cout << balls.size() << endl;
  }
  return 0;
}