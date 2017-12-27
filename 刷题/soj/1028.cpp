#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  int n;
  double a, b;
  string s;
  cin >> n;
  while (n--) {
    cin >> s;
    stack<double> ans;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] <= 'z' && s[i] >= 'a')
        ans.push(s[i] - 'a' + 1);
      else {
        a = ans.top();
        ans.pop();
        b = ans.top();
        ans.pop();
        switch (s[i]) {
          case '+':
            ans.push(a + b);
            break;
          case '-':
            ans.push(b - a);
            break;
          case '*':
            ans.push(a * b);
            break;
          case '/':
            ans.push(b / a);
            break;
        }
      }
    }
    printf("%.2lf\n", ans.top());
  }
  return 0;
}