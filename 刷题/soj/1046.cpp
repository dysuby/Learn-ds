#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, ans;
  int t = 0, index;
  while (cin >> s && s != "XXX") {
    index = 0;
    ans = "";
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] <= '9' && s[i] >= '0') {
        index = i - 1;
        t = 0;
        while (i < s.size() && s[i] <= '9' && s[i] >= '0') {
          t = t * 10 + s[i] - '0';
          ++i;
        }
        --i;
        while (t > 1) {
          ans.push_back(s[index]);
          --t;
        }
      } else {
        ans.push_back(s[i]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}