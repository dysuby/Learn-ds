#include <cstdio>
#include <climits>
using namespace std;

int main() {
  int n;
  while (scanf("%d", &n) && n) {
    int max = INT_MIN, num;
    while (n--) {
      scanf("%d", &num);
      max = num > max ? num : max;
    }
    printf("%d\n", max);
  }
  return 0;
}