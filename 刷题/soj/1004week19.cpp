#include <cstdio>
#include <stack>
using namespace std;

int pie[50], m, n;

void solution(int bottom) {
  if (bottom == 0) return;
  int max_index = 0;
  for (int i = 0; i <= bottom; ++i)
    max_index = pie[i] > pie[max_index] ? i : max_index;
  if (max_index != bottom) {
    if (max_index != 0) {
      stack<int> s;
      for (int i = 0; i <= max_index; ++i) s.push(pie[i]);
      for (int i = 0; i <= max_index; ++i) {
        int top = s.top();
        s.pop();
        pie[i] = top;
      }
      printf("%d ", m - max_index);
    }
    stack<int> s;
    for (int i = 0; i <= bottom; ++i) s.push(pie[i]);
    for (int i = 0; i <= bottom; ++i) {
      int top = s.top();
      s.pop();
      pie[i] = top;
    }
    printf("%d ", m - bottom);
  }
  solution(bottom - 1);
}

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) scanf("%d", &pie[i]);
    solution(m - 1);
    printf("0\n");
  }
  return 0;
}