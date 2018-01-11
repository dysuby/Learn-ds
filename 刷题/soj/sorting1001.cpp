#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

bool cmp(int &a, int &b) { return a > b; }

int main() {
  int n, m, num;
  cin >> n;
  while (n--) {
    priority_queue<int, vector<int>, bool (*)(int &, int &)> q(&cmp);
    cin >> m;
    while (m--) {
      cin >> num;
      q.push(num);
    }
    while (q.size()) {
      num = q.top();
      q.pop();
      cout << num << endl;
    }
  }
  return 0;
}