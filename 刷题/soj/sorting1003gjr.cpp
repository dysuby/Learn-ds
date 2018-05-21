#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct db {
  int index, col[12];
};

struct pos {
  int index, pri;
};

int n, m, cols, q;
db a[200];
pos priority[12];

bool cmp1(const pos &l, const pos &r) { return l.pri < r.pri; }

bool cmp2(const db &left, const db &right) {
  int index;
  const int *l = left.col, *r = right.col;
  for (int i = 0; i < cols; ++i) {
    index = priority[i].index;
    if (l[index] < r[index])
      return true;
    else if (l[index] > r[index])
      return false;
  }
  return left.index < right.index;
}

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d", &m, &cols);
    for (int i = 0; i < m; ++i) {
      a[i].index = i;
      for (int j = 0; j < cols; ++j)
        scanf("%d", &a[i].col[j]);
    }
    scanf("%d", &q);
    while (q--) {
      for (int i = 0; i < cols; ++i) {
        scanf("%d", &priority[i].pri);
        priority[i].index = i;
      }
      sort(priority, priority + cols, cmp1);
      sort(a, a + m, cmp2);
      printf("%d", a[0].index);
      for (int i = 1; i < m; ++i) printf(" %d", a[i].index);
      printf("\n");
    }
  }
  return 0;
}