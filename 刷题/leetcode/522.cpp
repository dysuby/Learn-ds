bool cmp(string &s1, string &s2) { return s1.size() > s2.size(); }
bool isSub(string &s1, string &s2) {
  // int j = 0;
  // for (int i = 0; i < s1.size(); ++i)
  // {
  //     while (j < s2.size() && s1[i] != s2[j])
  //         ++j;
  //     if (j == s2.size())
  //         return false;
  //     ++j;
  // }
  // return true;
  int i1 = 0, i2 = 0;
  while (i2 < s2.length()) {
    if (i1 < s1.length() && s1[i1] == s2[i2]) {
      i1++;
    }
    i2++;
  }
  return i1 == s1.length();
}
class Solution {
 public:
  int findLUSlength(vector<string> &strs) {
    map<string, int> m;
    for (int i = 0; i < strs.size(); ++i) ++m[strs[i]];
    sort(strs.begin(), strs.end(), cmp);
    for (int i = 0; i < strs.size(); ++i) {
      if (m[strs[i]] != 1) continue;
      int j = 0;
      for (; j < i; ++j) {
        if (isSub(strs[i], strs[j])) break;
      }
      if (j == i) return strs[i].size();
    }
    return -1;
  }
};
