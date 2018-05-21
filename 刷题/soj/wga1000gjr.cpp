#include <iostream>
using namespace std;

int set[100024];

int find(int a) {
  int ans = a;
  while (set[ans] != ans) ans = set[ans];
  set[a] = ans;
  return ans;
}

bool join(int a, int b) {
  int ap = find(a), bp = find(b);
  if (ap == bp) return false;
  set[bp] = ap;
  return true;
}

int main() {
  for (int i = 0; i <= 100000; ++i) set[i] = i;
  int a, b;
  while (cin >> a >> b)
    if (join(a, b)) cout << a <<  " " << b << endl;
  return 0;
}