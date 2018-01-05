#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n;
  while (n--) {
    cin >> m;
    vector<int> arr(m);
    for (int i = 0; i < m; ++i) cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = 0; i < m; ++i) cout << arr[i] << endl;
  }
  return 0;
}