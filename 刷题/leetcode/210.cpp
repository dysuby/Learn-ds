class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> degree(numCourses), ans;
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) degree[i] = 0;
    vector<vector<int>> list(numCourses);
    for (auto i : prerequisites) {
      ++degree[i.first];
      list[i.second].push_back(i.first);
    }
    for (int i = 0; i < numCourses; ++i)
      if (!degree[i]) q.push(i);
    while (q.size()) {
      int cur = q.front();
      q.pop();
      ans.push_back(cur);
      int size = list[cur].size();
      for (int i = 0; i < size; ++i) {
        --degree[list[cur][i]];
        if (!degree[list[cur][i]]) q.push(list[cur][i]);
      }
      if (q.empty() && ans.size() != numCourses) return vector<int>();
    }
    return ans;
  }
};