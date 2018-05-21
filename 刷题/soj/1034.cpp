#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct fuck {
  int col;
  int index;
  fuck() : col(-1), index(-1) {}
};

bool cmp(const fuck& a, const fuck& b) { return a.index > b.index; }

int main() {
  int col, n, e;
  while (cin >> col >> n) {
    vector<fuck> ope(col + 2);
    for (int i = 0; i < n; ++i) {
      cin >> e;
      ope[e].col = e;
      ope[e].index = i;
    }
    // cout << ope[0].index;
    sort(ope.begin(), ope.end(), cmp);
    int i = 0;
    while (ope[i].index != -1) ++i;
    cout << i-- << endl;
    cout << ope[i--].col;
    for (; i >= 0; --i) cout << ' ' << ope[i].col;
    cout << endl;
  }
  return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// int a[3000005], b[3000005];
// int visit[1000005];
// int main() {
//   int c, n, k;
//   while (scanf("%d %d", &c, &n) != EOF) {
//     for (int i = 0; i < n; i++) scanf("%d", &a[i]);
//     k = 0;
//     for (int i = n - 1; i >= 0; i--) {
//       if (!visit[a[i]]) {
//         b[k++] = a[i];
//         visit[a[i]] = 1;
//       }
//     }
//     printf("%d\n", k);
//     printf("%d", b[k - 1]);
//     for (int i = k - 2; i >= 0; i--) printf(" %d", b[i]);
//     printf("\n");
//     memset(visit, 0, sizeof(visit));
//   }
//   return 0;
// }