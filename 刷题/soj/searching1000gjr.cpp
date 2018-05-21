int binSearch(const int s[], const int size, const int target) {
  int left = 0, right = size - 1, mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (s[mid] < target)
      left = mid + 1;
    else if (s[mid] > target)
      right = mid - 1;
    else {
      while (s[++mid] == target) {
      }
      return mid - 1;
    }
  }
  return -1;
}

#include <iostream>
using namespace std;
int main() {
  int s[8] = {0, 1, 1, 3, 3, 3, 6, 6};

  cout << binSearch(s, 8, 2) << endl;  //输出5

  cout << binSearch(s, 8, 0) << endl;  //输出-1
}