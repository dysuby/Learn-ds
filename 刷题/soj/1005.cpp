#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
  return a.second > b.second;
}

vector<pair<int, string> > bonusList(vector<pair<string, int> > v) {
  if (!v.size()) return vector<pair<int, string> >();
  vector<pair<int, string> > ans(v.size());
  stable_sort(v.begin(), v.end(), cmp);
  int rank = 1, last = v[0].second;
  for (int i = 0; i < v.size(); ++i) {
    int temp = v[i].second;
    if (temp != last) ++rank;
    ans[i].first = rank;
    ans[i].second = v[i].first;
    last = temp;
  }
  return ans;
}

int main() {
  vector<pair<string, int> > test;
  bonusList(test);
  test.push_back(make_pair("zhang li", 280));
  test.push_back(make_pair("luo yan", 320));
  test.push_back(make_pair("gao min", 330));
  test.push_back(make_pair("wang ming", 320));
  auto ans = bonusList(test);
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}