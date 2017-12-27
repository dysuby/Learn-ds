#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool brackets(string s) {
  if (!s.size()) return true;
  stack<char> bra;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{')
      bra.push(s[i]);
    else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
      if (!bra.size()) return false;
      char temp = bra.top();
      if (s[i] == ')' && temp != '(')
        return false;
      else if (s[i] == '}' && temp != '{')
        return false;
      else if (s[i] == ']' && temp != '[')
        return false;
      bra.pop();
    }
  }
  if (bra.size())
    return false;
  return true;
}

int main() {
  string s;
  int n;
  cin >> n;
  while (n--) {
    cin >> s;
    cout << brackets(s);
  }
  return 0;
}