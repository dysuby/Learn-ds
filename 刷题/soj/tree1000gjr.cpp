#include <cstdio>
using namespace std;

int main() {
  int n, a, b;
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d", &a, &b);
    while (a != b) {
      if (a > b)
        a >>= 1;
      else
        b >>= 1;
    }
    printf("%d\n", a);
  }
  return 0;
}