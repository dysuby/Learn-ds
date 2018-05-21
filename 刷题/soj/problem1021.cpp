#include <iostream>
#include <stack>
using namespace std;

int couple[200005];

int main() {
  int n;
  while (cin >> n && n) {
    int a, b, tail = 2 * n;
    for (int i = 1; i <= n; ++i) {
      cin >> a >> b;
      couple[a] = i;
      couple[b] = i;
    }
    stack<int> s;
    for (int i = 1; i <= tail; ++i) {
      if (s.empty() && couple[i] != couple[tail]) {
        s.push(i);
      } else if (s.size()) {
        int top = s.top();
        if (couple[top] == couple[i])
          s.pop();
        else
          s.push(i);
      } else if (couple[tail] == couple[i]) {
        --tail;
      }
    }
    if (s.empty())
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}