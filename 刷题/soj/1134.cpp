#include <algorithm>
#include <cstdio>
using namespace std;

struct toy {
  long long have, need;
};

toy kid[10024];

bool cmp(const toy &a, const toy &b) {
  return a.need < b.need;
}

int main() {
  int n, s;
  while (scanf("%d%d", &n, &s) && n) {
    for (int i = 0; i < n; ++i) scanf("%lld%lld", &kid[i].have, &kid[i].need);
    sort(kid, kid + n, cmp);
    int i;
    for (i = 0; i < n; ++i) {
      if (kid[i].need > s) break;
      s += kid[i].have;
    }
    if (i == n)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}