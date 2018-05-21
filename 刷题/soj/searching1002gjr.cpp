#include <cstdio>
#define swap(x, y)      \
  {                     \
    long long temp = x; \
    x = y;              \
    y = temp;           \
  }

long long a[10000002];
long long have[20000002];

void find(long long s, long long e, long long k) {
  if (s >= e) return;
  long long pivot = a[e];
  long long i = s - 1, j = e;
  while (true) {
    while (a[++i] < pivot) {}
    while (a[--j] > pivot) {}
    if (i >= j) break;
    swap(a[i], a[j])
  }
  swap(a[i], a[e])
  if (i > k)
    find(s, i - 1, k);
  else if (i < k)
    find(i + 1, e, k);
}

int main() {
  long long n, k, index = 0, num;
  scanf("%lld%lld", &n, &k);
  for (long long i = 0; i < n; ++i) {
    scanf("%lld", &num);
    if (!have[num + 10000000]) {
      a[index] = num;
      ++index;
      have[num + 10000000] = 1;
    }
  }
  k = index - k;
  find(0, index - 1, k);
  printf("%lld\n", a[k]);
  return 0;
}