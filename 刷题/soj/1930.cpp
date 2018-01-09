#include <cstdio>

using namespace std;

int a[128];

int main() {
  int n, m, ans, temp;
  scanf("%d", &n);
  while (n--) {
    ans = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) {
      int min = i;
      for (int j = i + 1; j < m; ++j) {
        if (a[j] < a[min]) {
          ++ans;
          min = j;
        }
      }
      if (i != min) {
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
      }
    }
    printf("%d\n", ans);
  }
}