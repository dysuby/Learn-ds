class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int max = 0;
    map<char, int> pos;
    for (int i = 0, j = 0; i < s.size(); ++i) {
      if (pos.find(s[i]) != pos.end()) j = pos[s[i]] > j ? pos[s[i]] : j;
      max = (i - j + 1) > max ? (i - j + 1) : max;
      pos[s[i]] = i + 1;
    }
    return max;
  }
};