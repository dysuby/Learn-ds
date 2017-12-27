bool cmp(const string s1, const string s2) { return s1 + s2 > s2 + s1; }

class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> str;
    string ans;
    for (auto i : nums) str.push_back(to_string(i));
    sort(str.begin(), str.end(), cmp);
    for (auto s : str) ans += s;
    for (int i = 0; ans.size() > 1;) {
      if (ans[i] == '0')
        ans.erase(i, 1);
      else
        break;
    }
    return ans;
  }
};