#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

//约瑟夫环问题！F(i) = (F(i - 1) + M) % N

int solution(int m, int n) {
  if (n == 1)
    return 0;
  else
    return (solution(m, n - 1) + m) % n;
}

int main() {
  int n, x, y;
  while (cin >> n) {
    cin >> x >> y;
    if (n == 1) {
      printf("1 1\n");
      continue;
    }
    int ans = solution(x, n) + 1;
    cout << ans << " ";
    cout << ((ans + solution(y, n - 1)) % n) + 1 << endl;
  }
  return 0;
}


// int main() {
//   int n, x, y, count;
//   while (scanf("%d", &n) != EOF) {
//     scanf("%d%d", &x, &y);
//   if (n == 1) {
//     printf("1 1\n");
//     continue;
//   }
//   int count;
//   queue<int> q;
//   for (int i = 1; i <= n; ++i) q.push(i);
//   count = 0;
//   while (q.size() != 1) {
//     ++count;
//     int top = q.front();
//     q.pop();
//     if (count != x)
//       q.push(top);
//     else {
//       count = 0;
//       // cout << top << " ";
//     }
//   }
//   x = q.front();
//   q.pop();
//   int index = (x == n ? 1 : x + 1);
//   for (int i = 1; i < n; ++i) {
//     q.push(index);
//     if (index == n)
//       index = 1;
//     else
//       ++index;
//   }
//   count = 0;
//   while (q.size() != 1) {
//     ++count;
//     int top = q.front();
//     q.pop();
//     if (count != y)
//       q.push(top);
//     else {
//       count = 0;
//       // cout << top << " ";
//     }
//   }
//   y = q.front();
//     printf("%d %d\n", x, y);
//   }
//   return 0;
// }

// struct pos {
//   int l, r;
//   pos() : l(0), r(0) {}
// };

// int main() {
//   int n, x, y;
//   while (scanf("%d", &n) != EOF) {
//     scanf("%d%d", &x, &y);
//     if (n == 1) {
//       printf("1 1\n");
//       continue;
//     }
//     pos lamp[1200];
//     int un = 1, left = n, count = 0;
//     for (int i = 0; i <= n; ++i) {
//       lamp[i].r = i + 1;
//       lamp[i].l = i - 1;
//     }
//     lamp[n].r = 1;
//     lamp[1].l = n;
//     while (left != 1) {
//       ++count;
//       if (count == x) {
//         // cout << un << " ";
//         lamp[lamp[un].l].r = lamp[un].r;
//         lamp[lamp[un].r].l = lamp[un].l;
//         count = 0;
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
//     count = 0;
//     while (left != n - 1) {
//       ++count;
//       if (count == y) {
//         // cout << un << " ";
//         lamp[lamp[un].l].r = lamp[un].r;
//         lamp[lamp[un].r].l = lamp[un].l;
//         count = 0;
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
//   for (int i = 1; i <= 100; ++i) {
//     for (int j = 1; j <= 100; ++j) {
//       for (int k = 1; k <= 100; ++k) {
//         cal(i, j, k);
//         cout << i << " " << j << " " << k << endl;
//       }
//     }
//   }
//   return 0;
// }

// int main() {
//   int n, x, y;
//   while (scanf("%d", &n)) {
//     scanf("%d%d", &x, &y);
//     vector<int> lamp(n + 1, 0);
//     int left = n, index = 1, count = 0;
//     while (left != 1) {
//       if (!lamp[index]) ++count;
//       if (count == x) {
//         lamp[index] = 1;
//         --left;
//         count = 0;
//       }
//       ++index;
//       if (index == n + 1) index = 1;
//     }
//     for (index = 1; lamp[index]; ++index) {
//     }
//     x = index;
//     count = 0;
//     while (left != n - 1) {
//       if (lamp[index]) ++count;
//       if (count == y) {
//         lamp[index] = 0;
//         ++left;
//         count = 0;
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
