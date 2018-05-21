#include <cstdio>
using namespace std;

int main() {
  long long n, m;
  scanf("%lld%lld", &n, &m);
  long long arr[101024];
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &arr[i]);
  }
  int cm, l, r, v;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &cm);
    if (cm == 1) {
      scanf("%d%d%d", &l, &r, &v);
      if (v == 1)
        continue;
      for (int j = l; j <= r; ++j)
        if (arr[j] % v == 0)
          arr[j] /= v;
    } else {
      long long sum = 0;
      scanf("%d%d", &l, &r);
      for (int j = l; j <= r; ++j)
        sum += arr[j];
      printf("%lld\n", sum);
    }
  }
  return 0;
}