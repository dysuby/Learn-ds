#include <iostream>
#include <vector>
#define TEST 999
using namespace std;

class MergeSort {
  private:
    void msort(vector<int> &arr, int temp[], int start, int end) {
      if (start < end) {
        int center = (start + end) / 2;
        msort(arr, temp, start, center);
        msort(arr, temp, center + 1, end);
        merge(arr, temp, start, center + 1, end);
      }
    }
    void merge(vector<int> &arr, int temp[], int start, int middle, int end) {
      int i = start, j = middle, begin = start;
      while (i < middle && j <= end)
        if (arr[i] > arr[j])
          temp[start++] = arr[j++];
        else
          temp[start++] = arr[i++];
      while (i < middle) 
        temp[start++] = arr[i++];
      while (j <= end)
        temp[start++] = arr[j++];
      for (int k = begin; k <= end; ++k)
        arr[k] = temp[k];
    }
  public:
    vector<int>& sort(vector<int> &arr) {
      if (!arr.size())
        return arr;
      int *temp = new int[arr.size() * sizeof(int)];
      msort(arr, temp, 0, arr.size() - 1);
      return arr;
    }
};


int test() {
  MergeSort solution;
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
  }
  return 0;
}
