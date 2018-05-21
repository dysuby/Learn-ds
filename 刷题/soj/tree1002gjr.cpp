#include <iostream>
using namespace std;

int l, r;

void solution(int a, int b) {
  if (a == 1 && b == 1) return;
  if (a > b) {
    ++l;
    solution(a - b, b);
  } else {
    ++r;
    solution(a, b - a);
  }
}

int main() {
  int n, a, b;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    l = 0;
    r = 0;
    cin >> a >> b;
    solution(a, b);
    cout << "Scenario #" << i << ":" << endl;
    cout << l << " " << r << endl;
  }
  return 0;
}