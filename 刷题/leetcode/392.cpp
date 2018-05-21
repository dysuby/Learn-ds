class Solution {
 public:
  bool isSubsequence(string s, string t) {
    if (t.size() == 0) return !s.size();
    int size = t.size(), index = 0, sub = s.size();
    for (int i = 0; i < size; ++i) {
      if (t[i] == s[index]) ++index;
      if (index == sub) return true;
    }
    return false;
  }
};