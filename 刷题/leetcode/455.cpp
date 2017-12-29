bool cmp(const int& a, const int& b) { return a > b; }
class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    if (!g.size() || !s.size()) return 0;
    sort(g.begin(), g.end(), cmp);
    sort(s.begin(), s.end(), cmp);
    int gsize = g.size(), ssize = s.size();
    int i, j;
    for (i = 0, j = 0; i != gsize && j != ssize; ++i)
      if (g[i] <= s[j]) ++j;
    return j + 1;
  }
};