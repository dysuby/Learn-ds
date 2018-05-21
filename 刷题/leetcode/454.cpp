class Solution {
 public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C,
                   vector<int>& D) {
    map<int, int> sum;
    int ans = 0;
    for (auto a : A)
      for (auto b : B) ++sum[a + b];
    for (auto c : C) {
      for (auto d : D) {
        auto i = sum.find(-c - d);
        if (i != sum.end()) ans += i->second;
      }
    }
    return ans;
  }
};