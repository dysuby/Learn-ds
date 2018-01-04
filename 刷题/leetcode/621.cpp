class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    int size = tasks.size();
    if (size <= 1) return size;
    int count[26] = {0}, max = 0, num = 0;
    for (int i = 0; i < size; ++i) {
      ++count[tasks[i] - 'A'];
      max = max > count[tasks[i] - 'A'] ? max : count[tasks[i] - 'A'];
    }
    for (int i = 0; i < 26; ++i)
      if (max == count[i]) ++num;
    int ans = (max - 1) * (n + 1) + num;
    return size > ans ? size : ans;
  }
};