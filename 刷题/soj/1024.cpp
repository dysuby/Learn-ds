#include <iostream>
#include <vector>
using namespace std;

double mean() {
  int n;
  cin >> n;
  double ans = 0;
  vector<int> data(n);
  vector<double> p(n);
  for (int i = 0; i < n; ++i) cin >> data[i];
  for (int i = 0; i < n; ++i) cin >> p[i];
  for (int i = 0; i < n; ++i) ans += data[i] * p[i];
  return ans;
}