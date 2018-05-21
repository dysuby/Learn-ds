class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    int size = s.size(), psize = p.size();
    vector<int> ans, pv(26), sv(26);
    if (psize == 0 || size < psize) return ans;
    for (int i = 0; i < psize; ++i) {
      ++pv[p[i] - 'a'];
      ++sv[s[i] - 'a'];
    }
    if (pv == sv) ans.push_back(0);
    for (int i = 1; i <= size - psize; ++i) {
      ++sv[s[i + psize - 1] - 'a'];
      --sv[s[i - 1] - 'a'];
      if (pv == sv) ans.push_back(i);
    }
    return ans;
  }
};

// "cbaebabacd"
//     "abc"
