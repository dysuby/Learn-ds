#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct vertex {
  int dis, known;
  vertex(int d = -1, int k = 0):dis(d),known(k) {}
};

int main() {
  int n, m, a, b;
  cin >> n;
  while (n--) {
    cin >> m;
    vector<int> graph[101];
    queue<int> q;
    vertex vertexs[101];
    vertexs[0].dis = 0;
    for (int i = 0; i < m; ++i) {
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    q.push(0);
    while (q.size()) {
      int top = q.front();
      q.pop();
      vertexs[top].known = 1;
      for (int i = 0; i < graph[top].size(); ++i) {
        int v = graph[top][i];
        if (vertexs[v].dis == -1 && vertexs[v].known == 0) {
          vertexs[v].dis = vertexs[top].dis + 1;
          q.push(v);
        }
      }
    }
    for (int i = 1; i <= 100; ++i)
      if (vertexs[i].dis != -1) cout << i << ':' << vertexs[i].dis << endl;
    cout << "---" << endl;
  }
  return 0;
}