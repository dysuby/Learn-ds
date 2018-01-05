#include <iostream>
#include <vector>
using namespace std;

struct pos {
  int l, r;
};

pos balls[500005];

int main() {
  int n, ball, m, side, a, b;
  cin >> n;
  while (n--) {
    cin >> ball >> m;
    for (int i = 0; i <= ball; ++i) {
      balls[i].r = i + 1;
      balls[i].l = i - 1;
    }
    while (m--) {
      cin >> side >> a >> b;
      balls[balls[a].l].r = balls[a].r;
      balls[balls[a].r].l = balls[a].l;
      if (side == 1) {
        balls[balls[b].l].r = a;
        balls[a].l = balls[b].l;
        balls[a].r = b;
        balls[b].l = a;
      } else {
        balls[a].r = balls[b].r;
        balls[balls[b].r].l = a;
        balls[a].l = b;
        balls[b].r = a;
      }
    }
    for (int i = 0; balls[i].r != ball + 1; i = balls[i].r) cout << balls[i].r << " ";
    cout << endl;
  }
  return 0;
}