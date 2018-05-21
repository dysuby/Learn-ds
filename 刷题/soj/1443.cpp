#include <cstdio>
#include <queue>
using namespace std;

struct work {
  int index, pri;
  work(int i, int p) : index(i), pri(p) {}
};

int main() {
  int t, n, m, p;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    queue<work> q;
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &p);
      q.push(work(i, p));
      pq.push(p);
    }
    int ans = 0;
    while (true) {
      work top = q.front();
      q.pop();
      if (pq.top() > top.pri) {
        q.push(top);
        continue;
      } else {
        ++ans;
        pq.pop();
        if (top.index == m) break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}