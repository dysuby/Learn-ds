#include <cstdio>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
  int n, t, num;
  while (cin >> n >> t) {
    double sum = 0;
    vector<list<int>> hash(t);
    for (int i = 0; i < n; ++i) {
      cin >> num;
      int val = num % t;
      hash[val].push_front(num);
      sum += hash[val].size();
    }
    for (int i = 0; i < t; ++i) {
      for (auto ite = hash[i].begin(); ite != hash[i].end(); ++ite)
        cout << *ite << " ";
      cout << endl;
    }
    printf("%.3lf\n", sum / n);
  }
  return 0;
}