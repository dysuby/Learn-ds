#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  string s;
  while (cin >> s) {
    stack<int> box;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(')
        box.push(1);
      else if (s[i] == ')')
        box.pop();
      else {
        cout << box.size() << endl;
        break;
      }
    }
  }
  return 0;
}