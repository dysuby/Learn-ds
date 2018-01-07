#include <cstdio>
#include <iostream>
using namespace std;

struct pos {
  int l, r;
};

int main() {
  int n, x, y;
  while (scanf("%d", &n)) {
    scanf("%d%d", &x, &y);
    if (n == 1) {
      printf("1 1\n");
      continue;
    }
    pos lamp[1200];
    int un = 1, left = n, num = 0;
    for (int i = 0; i <= n; ++i) {
      lamp[i].r = i + 1;
      lamp[i].l = i - 1;
    }
    lamp[n].r = 1;
    lamp[1].l = n;
    while (left != 1) {
      ++num;
      if (num == x) {
        cout << un << " ";
        lamp[lamp[un].l].r = lamp[un].r;
        lamp[lamp[un].r].l = lamp[un].l;
        num = 0;
        --left;
      }
      un = lamp[un].r;
    }
    x = un;
    for (int i = 0; i <= n; ++i) {
      lamp[i].r = i + 1;
      lamp[i].l = i - 1;
    }
    lamp[n].r = 1;
    lamp[1].l = n;
    if (un == 1) {
      lamp[n].r = 2;
      lamp[2].l = n;
      ++un;
    } else if (un == n) {
      lamp[1].l = n - 1;
      lamp[n - 1].r = 1;
      un = 1;
    } else {
      lamp[un - 1].r = un + 1;
      lamp[un + 1].l = un - 1;
      ++un;
    }
    num = 0;
    while (left != n - 1) {
      ++num;
      if (num == y) {
        cout << un << " ";
        lamp[lamp[un].l].r = lamp[un].r;
        lamp[lamp[un].r].l = lamp[un].l;
        num = 0;
        ++left;
      }
      un = lamp[un].r;
    }
    y = un;
    printf("%d %d\n", x, y);
  }
  return 0;
}

// int main() {
//   int n, x, y;
//   while (scanf("%d", &n)) {
//     scanf("%d%d", &x, &y);
//     vector<int> lamp(n + 1, 0);
//     int left = n, index = 1, num = 0;
//     while (left != 1) {
//       if (!lamp[index]) ++num;
//       if (num == x) {
//         lamp[index] = 1;
//         --left;
//         num = 0;
//       }
//       ++index;
//       if (index == n + 1) index = 1;
//     }
//     for (index = 1; lamp[index]; ++index) {
//     }
//     x = index;
//     num = 0;
//     while (left != n - 1) {
//       if (lamp[index]) ++num;
//       if (num == y) {
//         lamp[index] = 0;
//         ++left;
//         num = 0;
//       }
//       ++index;
//       if (index == n + 1) index = 1;
//     }
//     for (index = 1; !lamp[index]; ++index) {
//     }
//     y = index;
//     printf("%d %d\n", x, y);
//   }
//   return 0;
// }
