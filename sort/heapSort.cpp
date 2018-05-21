#include <iostream>
#include <random>
#include <vector>
#define leftChild(i) ((i)*2 + 1)

#define TEST 999
using namespace std;

class heapSort {
 private:
  void down(vector<int> &arr, int index, int size) {
    int ele = arr[index], child(0);
    for (; leftChild(index) < size; index = child) {
      child = leftChild(index);
      if (child + 1 < size && arr[child] < arr[child + 1]) ++child;
      if (arr[child] > ele)
        arr[index] = arr[child];
      else
        break;
    }
    arr[child] = ele;
  }

 public:
  vector<int> &sort(vector<int> &arr) {
    if (arr.size() == 0) return arr;
    int size = arr.size();
    for (int index = size / 2; index >= 0; --index) down(arr, index, size);
    for (int index = size - 1; index > 0; --index) {
      int temp = arr[0];
      arr[0] = arr[index];
      arr[index] = temp;
      down(arr, 0, index);
    }
    return arr;
  }
};

int test() {
  heapSort solution;
  vector<int> test;
  default_random_engine e(time(0));
  uniform_int_distribution<unsigned> u(0, TEST);
  for (int i = 0; i < TEST; ++i) {
    test.push_back(u(e));
  }
  solution.sort(test);
  int prev = 0;
  for (int index = 0; index < TEST; ++index) {
    if (prev > test[index]) cout << "error" << endl;
    prev = test[index];
  }
  return 0;
}

int main() {
  test();
  return 0;
}
