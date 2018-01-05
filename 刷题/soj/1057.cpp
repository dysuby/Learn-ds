#include <climits>
int findMax(vector<int> &v) {
  int count = 0, max = INT_MIN;
  for (int i = v.size() - 1; i >= 0; --i) max = max > v[i] ? max : v[i];
  for (int i = v.size() - 1; i >= 0; --i)
    if (max == v[i]) ++count;
  return count;
}