#include <iostream>
#include <vector>
#include <algorithm>
#define EMPTY (-1)
#define BORROW (1)
#define RETURN (0)
using namespace std;

struct event {
  int id, flag, time;
  event(int n = EMPTY, int f = EMPTY, int t = EMPTY): id(n), flag(f), time(t) {}
};

bool cmp(const event &k1, const event &k2) {
  if (k1.time < k2.time)
    return true;
  if (k1.time == k2.time && k1.flag < k2.flag)
    return true;
  if (k1.time == k2.time && k1.flag == k2.flag && k1.id < k2.id)
    return true;
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  int no, begin, end;
  vector<event> tasks;
  int* pos = new int[n + 1];
  for (int i = 0; i <= n; ++i)
    pos[i] = i;
  int max = 0;
  for (int i = 0; i < m; ++i) {
    cin >> no >> begin >> end;
    tasks.push_back(event(no, BORROW, begin));
    tasks.push_back(event(no, RETURN, begin + end));
    if (max < end + begin)
      max = end + begin;
  }
  sort(tasks.begin(), tasks.end(), cmp);
  for (int i = 0; i < tasks.size(); ++i) {
    if (tasks[i].flag == BORROW) {
      int j;
      for (j = 1; pos[j] != tasks[i].id; ++j) {}
      pos[j] = EMPTY;
    }
    if (tasks[i].flag == RETURN) {
      int j;
      for (j = 1; pos[j] != EMPTY; ++j) {}
      pos[j] = tasks[i].id;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << pos[i] << " ";
  }
  delete[] pos;
  return 0;
}