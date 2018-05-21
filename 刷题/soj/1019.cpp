#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct vertex {
  int known, dis;
  vertex(int k = 0, int d = -1):known(k), dis(d) {}
};

int main() {
  int n, m, start, end, a, b, size;
  cin >> n;
  while (n--) {
    cin >> size >> m >> start >> end;
    vector<vector<int> >graph(size);
    queue<int> q;
    vector<vertex> vertexs(size);
    vertexs[start].dis = 0;
    for (int i = 0; i < m; ++i) {
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    q.push(start);
    while (q.size()) {
      int top = q.front();
      vertexs[top].known = 1;
      q.pop();
      for (int i = 0; i < graph[top].size(); ++i) {
        int v = graph[top][i];
        if (vertexs[v].dis == -1 && vertexs[v].known == 0) {
          vertexs[v].dis = vertexs[top].dis + 1;
          q.push(v);
        }
      }
    }
    cout << vertexs[end].dis << endl;
  }
  return 0;
}