#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct dance {
  int start, end;
  dance(int s, int e) : start(s), end(e) {}
};

bool ok(const dance &d, vector<dance> cur) {
  return find_if(cur.begin(), cur.end(), [d](const dance &i) -> bool {
           if (d.start > i.end || d.end < i.start) return false;
           return true;
         }) == cur.end();
}

void back(vector<dance> ans, const vector<dance> &all, int &max) {
  if (ans.size() == all.size()) return;
  for (int i = 0; i < all.size(); ++i) {
    if (ok(all[i], ans)) {
      ans.push_back(all[i]);
      max = max > ans.size() ? max : ans.size();
      back(ans, all, max);
      ans.pop_back();
    }
  }
}

int main() {
  int n, m, a, b;
  cin >> n;
  while (n--) {
    cin >> m;
    vector<dance> all;
    for (int i = 0; i < m; ++i) {
      cin >> a >> b;
      all.push_back(dance(a, b));
    }
    int max = 0;
    vector<dance> ans;
    back(ans, all, max);
    cout << max << endl;
  }
  return 0;
}