#include <cstring>
#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

void findIndegree(vector<list<int> > &graph, vector<int> &indegree) {
  for (int i = 1; i < graph.size(); ++i)
    for (auto j = graph[i].begin(); j != graph[i].end(); ++j) ++indegree[*j];
}

int main() {
  int n, a, b, size, m;
  cin >> n;
  while (n--) {
    cin >> size >> m;
    vector<list<int> > graph(size + 1);
    for (int i = 0; i < m; ++i) {
      cin >> a >> b;
      graph[a].push_back(b);
    }
    vector<int> indegree(size + 1);
    findIndegree(graph, indegree);
    stack<int> s;
    for (int i = 1; i <= size; ++i)
      if (!indegree[i]) s.push(i);
    while (s.size()) {
      int top = s.top();
      // cout << top << " ";
      --size;
      s.pop();
      for (auto i = graph[top].begin(); i != graph[top].end(); ++i)
        if (!--indegree[*i]) s.push(*i);
    }
    if (size)
      cout << "There exists a cycle." << endl;
    else
      cout << "It is acyclic." << endl;
  }
}

// int size;
// bool flag = true;

// void isAcyclic(int start, vector<int> &visited, vector<vector<bool> > &graph)
// {
//   visited[start] = 1;
//   for (int i = 1; i <= size; ++i) {
//     if (i == start) continue;
//     if (graph[start][i] && visited[i] == 0)
//       isAcyclic(i, visited, graph);
//     else if (graph[start][i] && visited[i] == 1)
//       flag = false;
//   }
//   visited[start] = 2;
// }

// int main() {
//   int n, m, a, b;
//   cin >> n;
//   while (n--) {
//     flag = true;
//     cin >> size >> m;
//     vector<vector<bool> > graph(size + 1, vector<bool>(size + 1));
//     for (int i = 0; i < m; ++i) {
//       cin >> a >> b;
//       graph[a][b] = 1;
//     }
//     vector<int> visited(size + 1);
//     for (int i = 1; i <= size; ++i)
//       if (visited[i] == 0) isAcyclic(i, visited, graph);
//     if (!flag)
//       cout << "There exists a cycle." << endl;
//     else
//       cout << "It is acyclic." << endl;
//   }
// }
