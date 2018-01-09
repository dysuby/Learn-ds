#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

// int light[1200];

int main() {
  int n, x, y, num;
  while (scanf("%d", &n)) {
    scanf("%d%d", &x, &y);
    if (n == 1) {
      cout << "1 1\n";
      continue;
    }
    // memset(light, 0, sizeof(int) * 1200);
    queue<int> q;
    for (int i = 1; i <= n; ++i) q.push(i);
    num = 0;
    while (q.size() != 1) {
      ++num;
      int top = q.front();
      q.pop();
      if (num != x)
        q.push(top);
      else {
        num = 0;
        // cout << top << " ";
      }
    }
    x = q.front();
    q.pop();
    int index = x == n ? 1 : x + 1;
    for (int i = 1; i < n;) {
      if (index != x) {
        q.push(index);
        ++i;
      }
      if (index == n)
        index = 1;
      else
        ++index;
    }
    num = 0;
    while (q.size() != 1) {
      ++num;
      int top = q.front();
      q.pop();
      if (num != y)
        q.push(top);
      else {
        num = 0;
        // cout << top << " ";
      }
    }
    y = q.front();
    printf("%d %d\n", x, y);
  }
  return 0;
}

// struct pos {
//   int l, r;
// };

// int main() {
//   int n, x, y;
//   while (scanf("%d", &n)) {
//     scanf("%d%d", &x, &y);
//     if (n == 1) {
//       printf("1 1\n");
//       continue;
//     }
//     pos lamp[1200];
//     int un = 1, left = n, num = 0;
//     for (int i = 0; i <= n; ++i) {
//       lamp[i].r = i + 1;
//       lamp[i].l = i - 1;
//     }
//     lamp[n].r = 1;
//     lamp[1].l = n;
//     while (left != 1) {
//       ++num;
//       if (num == x) {
//         cout << un << " ";
//         lamp[lamp[un].l].r = lamp[un].r;
//         lamp[lamp[un].r].l = lamp[un].l;
//         num = 0;
//         --left;
//       }
//       un = lamp[un].r;
//     }
//     x = un;
//     for (int i = 0; i <= n; ++i) {
//       lamp[i].r = i + 1;
//       lamp[i].l = i - 1;
//     }
//     lamp[n].r = 1;
//     lamp[1].l = n;
//     if (un == 1) {
//       lamp[n].r = 2;
//       lamp[2].l = n;
//       ++un;
//     } else if (un == n) {
//       lamp[1].l = n - 1;
//       lamp[n - 1].r = 1;
//       un = 1;
//     } else {
//       lamp[un - 1].r = un + 1;
//       lamp[un + 1].l = un - 1;
//       ++un;
//     }
//     num = 0;
//     while (left != n - 1) {
//       ++num;
//       if (num == y) {
//         cout << un << " ";
//         lamp[lamp[un].l].r = lamp[un].r;
//         lamp[lamp[un].r].l = lamp[un].l;
//         num = 0;
//         ++left;
//       }
//       un = lamp[un].r;
//     }
//     y = un;
//     printf("%d %d\n", x, y);
//   }
//   return 0;
// }

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
