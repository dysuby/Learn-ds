#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, each;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) cin >> arr[i];
  cin >> m;
  while (m--) {
    cin >> each;
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
      mid = (tail + head) / 2;
      if (arr[mid] < each)
        head = mid + 1;
      else if (arr[mid] > each)
        tail = mid - 1;
      else
        break;
    }
    if (arr[mid] == each)
      cout << "1 ";
    else
      cout << "0 ";
  }
  cout << endl;
  return 0;
}