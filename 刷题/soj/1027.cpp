#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  string ans, s;
  stack<char> pos;
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] <= 'z' && s[i] >= 'a' || s[i] <= 'Z' && s[i] >= 'A')
      ans.push_back(s[i]);
    else {
      if (s[i] == '+' || s[i] == '-') {
        while (pos.size()) {
          ans.push_back(pos.top());
          pos.pop();
        }
        pos.push(s[i]);
      } else {
        while (pos.size() && pos.top() != '+' && pos.top() != '-') {
          ans.push_back(pos.top());
          pos.pop();
        }
        pos.push(s[i]);
      }
    }
  }
  while (pos.size()) {
    ans.push_back(pos.top());
    pos.pop();
  }
  cout << ans;
  return 0;
}