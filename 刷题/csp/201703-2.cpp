#include <iostream>
using namespace std;

int main() {
  int n, m, students[1024], id, move, temp, pos[1024], flag;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    students[i] = i;
    pos[i] = i;
  }
  for (int i = 0; i < m; ++i) {
    cin >> id >> move;
    flag = move > 0 ? 1 : -1;
    for (int j = 0; j != move; j += flag) {
      students[pos[id]] = students[pos[id] + flag];
      pos[students[pos[id] + flag]] -= flag;
      pos[id] += flag;
    }
    students[pos[id]] = id;
  }
  for (int i = 1; i <= n; ++i)
    cout << students[i] << ' ';
  return 0;
}