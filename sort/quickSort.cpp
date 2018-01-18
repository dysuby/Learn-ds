#include <vector>
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

#define swap(x, y) {int temp = x; x = y; y = temp;}
#define CUTOFF 10
#define TEST 999

class quickSort {
  private:
    inline int median(vector<int> &arr, int left, int right) {
      int med = (left + right) / 2;
      if (arr[left] > arr[med])
        swap(arr[left], arr[med])
      if (arr[med] > arr[right])
        swap(arr[med], arr[right])
      if (arr[left] > arr[med])
        swap(arr[left], arr[med])
      swap(arr[med], arr[right - 1]);
      return arr[right - 1];
    }

    void qsort(vector<int> &arr, int left, int right) {
      if (/* left < right */right - left >= CUTOFF) {
        int pivot = median(arr, left, right);
        int i = left, j = right - 1;
        while (i < j) {
          while (arr[++i] < pivot) {}
          while (arr[--j] > pivot) {}
          if (i < j)
            swap(arr[i], arr[j])
        }
        swap(arr[i], arr[right - 1]);
        qsort(arr, left, i - 1);
        qsort(arr, i + 1, right);
      } else {
        insertSort(arr, left, right);
      }
    }
    void insertSort(vector<int> &arr, int left, int right) {
      for (int i = 1; i <= right; ++i) {
        int temp = arr[i], j;
        for (j = i; j > 0 && arr[j - 1] > temp; --j)
          arr[j] = arr[j - 1];
        arr[j] = temp;        
      }
    }
  public:
    vector<int>& sort(vector<int> &arr) {
      if (!arr.size())
        return arr;
      qsort(arr, 0, arr.size() - 1);
      return arr;
    }
};


int test() {
  quickSort solution;
  vector<int> test;
  default_random_engine e(time(0));
  uniform_int_distribution<unsigned> u(0, TEST);
  for (int i = 0; i < TEST; ++i) {
    test.push_back(u(e));
  }
  solution.sort(test);
  int prev = 0;
  for (int index = 0; index < TEST; ++index) {
    if (prev > test[index])
      cout << "error" << endl;
    prev = test[index];
    // cout << test[index] << " ";
  }
  cout << endl;
  return 0;
}


int main() {
  test();
  return 0;
}