#include <iostream>
#include <stack>
using namespace std;

void back(stack<int> s, int bomb, int &count) {
  if (bomb == 0) {
    ++count;
    return;
  }
  if (s.size()) {
    int top = s.top();
    s.pop();
    back(s, bomb, count);
    s.push(top);
  }
  s.push(bomb);
  back(s, bomb - 1, count);
}

int main() {
  int n, bomb;
  cin >> n;
  while (n--) {
    cin >> bomb;
    stack<int> s;
    int count = 0;
    back(s, bomb, count);
    cout << count << endl;
  }
  return 0;
}