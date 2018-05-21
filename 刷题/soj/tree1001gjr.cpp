#include <iostream>
#include <string>
using namespace std;

string pre, in;
int count = 0;

void solution(int s1, int e1, int s2, int e2) {
  if (s1 >= e1) return;
  int i = s2;
  while (i <= e2 - 1 && pre[s1 + 1] != in[i]) {
    ++i;
  }
  if (i == e2 - 1) ++count;
  solution(s1 + 1, s1 + i - s2 + 1, s2, i);
  solution(s1 + i - s2 + 2, e1, i + 1, e2 - 1);
}

int pow (int c) {
  if (c == 0) return 1;
  if (c == 1) return 2;
  return pow(c / 2) * pow(c / 2) * pow (c & 1);
}

int main() {
  while (cin >> pre >> in) {
    int size = pre.size();
    solution(0, size - 1, 0, size - 1);
    cout << pow(count);
  }
  return 0;
}