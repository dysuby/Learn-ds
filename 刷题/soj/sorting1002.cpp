#include <cstdio>
#include <queue>
using namespace std;

bool cmp(int &a, int &b) { return a > b; }

int main() {
  int n, k, num, index;
  while (scanf("%d%d", &n, &k) && n && k) {
    priority_queue<int, vector<int>, bool (*)(int &, int &)> q(&cmp);
    index = n;
    while (index--) {
      scanf("%d", &num);
      q.push(num);
    }
    num = q.top();
    printf("%d", num);
    q.pop();
    for (int i = 1; i < n; ++i) {
      if (i % k == 0) {
        num = q.top();
        printf(" %d", num);
      }
      q.pop();
    }
    printf("\n");
  }
  return 0;
}