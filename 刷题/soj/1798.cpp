#include <iostream>
using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    n *= n;
    if (n & 1)
      cout << "Bob" << endl;
    else
      cout << "Alice" << endl;
  }
}