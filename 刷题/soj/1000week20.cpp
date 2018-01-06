#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int k = 0; k < n; ++k) cout << a[k] << " ";
  cout << endl;
  for (int i = 1; i < n; ++i) {
    int temp = a[i], j = 0;
    for (j = i; j > 0 && temp < a[j - 1]; --j) a[j] = a[j - 1];
    if (j == i) continue;
    a[j] = temp;
    for (int k = 0; k < n; ++k) cout << a[k] << " ";
    cout << endl;
  }
  return 0;
}