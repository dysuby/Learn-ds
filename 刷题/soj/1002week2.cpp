#include <iostream>
#include <stack>
using namespace std;

int main() {
  int n, num, top, shot[10] = {0}, order[10] = {}, index = 0;
  stack<int> s;
  cin >> n;
  while (n--) {
    index = 0;
    for (int i = 0; i < 10; ++i) cin >> shot[i];
    for (int i = 9; i >= 0; --i) {
      if (s.empty() || s.top() < shot[i]) {
        s.push(shot[i]);
      } else {
        while (s.size() && s.top() > shot[i]) {
          order[index++] = s.top();
          s.pop();
        }
        s.push(shot[i]); 
      }
    }
    while (s.size()) {
      order[index++] = s.top();
      s.pop();
    }
    for (int i = 1; i < 10; ++i) {
      if (order[i] != order[i - 1] - 1) {
        cout << "No" << endl;
        break;
      } else if (i == 9) {
        cout << "Yes" << endl;
      }
    }
  }
  return 0;
}