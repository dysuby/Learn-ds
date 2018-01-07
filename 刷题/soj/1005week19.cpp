#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int n, num;
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &num);
    v[i] = num;
  }
  sort(v.begin(), v.end());
  for (auto &i : v) printf("%d ", i);
  printf("\n");
  int size = v.size();
  if (size & 1) printf("%d\n", v[size >> 1]);
  else printf("%d\n", (v[size >> 1] + v[(size >> 1) - 1]) >> 1);
  return 0;
}