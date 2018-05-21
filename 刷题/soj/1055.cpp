#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n, monkey, m;
  cin >> n;
  while (n--) {
    cin >> monkey >> m;
    queue<int> q;
    for (int i = 1; i <= monkey; ++i) q.push(i);
    int num = 1, cur;
    while (q.size() != 1) {
      cur = q.front();
      q.pop();
      if (num != m) {
        q.push(cur);
        ++num;
      } else {
        num = 1;
      }
    }
    cout << q.front() << endl;
  }
  return 0;
}