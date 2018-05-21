#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n,m, x, count;
  cin >> m;
  while (m--) {
    scanf("%d%d", &n, &x);
    if (n == 1) {
      printf("1\n");
      continue;
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) q.push(i);
    count = 0;
    while (q.size() != 1) {
      ++count;
      int top = q.front();
      q.pop();
      if (count != x)
        q.push(top);
      else {
        count = 0;
        // cout << top << " ";
      }
    }
    printf("%d\n", q.front());
  }
  return 0;
}