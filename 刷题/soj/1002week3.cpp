#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n, m;
  cin >> n;
  while (n--) {
    cin >> m;
    queue<int> q;
    for (int i = 1; i <= m; ++i) q.push(i);
    while (q.size() > 1) {
      int top = q.front();
      cout << top << " ";
      q.pop();
      top = q.front();
      q.pop();
      q.push(top);
    }
    cout << q.front() << " " << endl;
  }
  return 0;
}