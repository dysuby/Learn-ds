class Solution {
 public:
  int maxProduct(vector<string> &words) {
    vector<pair<int, int>> m;
    for (auto word : words) {
      int first = word.size();
      int second = 0;
      for (auto c : word) second |= 1 << (c - 'a');
      m.push_back(make_pair(first, second));
    }
    sort(m.begin(), m.end(),
         [](const pair<int, int> &p1, const pair<int, int> &p2) {
           return p1.first > p2.first;
         });
    int max = 0;
    for (int i = 0; i < m.size(); ++i) {
      for (int j = i + 1; j < m.size(); ++j) {
        if (m[i].first * m[j].first <= max) break;
        if (!(m[i].second & m[j].second))
          max = (m[i].first * m[j].first > max) ? m[i].first * m[j].first : max;
      }
    }
    return max;
  }
};