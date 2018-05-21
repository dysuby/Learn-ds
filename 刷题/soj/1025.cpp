#include <algorithm>
#include <map>
#include <vector>
using namespace std;

pair<double, int> Q1(vector<double> v) {
  sort(v.begin(), v.end());
  return make_pair(v[v.size() / 4], v.size() / 4);
}