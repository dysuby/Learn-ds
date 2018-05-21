#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <ctime>

#define TEST 999
using namespace std;

class sort {
 public:
  void shellsort(vector<int> &ele, string choice = "Shell") {
    vector<int> *seq;
    if (choice == "Sedgewick") {
      seq = &Sedgewick;
    } else if (choice == "Hibbard") {
      seq = &Hibbard;
    } else {
      seq = new vector<int>;
      for (int i = ele.size() / 2; i > 0; i /= 2) seq->insert(seq->begin(), i);
    }
    int temp = 0, j = 0, k = seq->size() - 1;
    while ((*seq)[k] > ele.size() / 2) --k;
    for (int inc = (*seq)[k]; true; inc = (*seq)[--k]) {
      for (int index = inc; index < ele.size(); ++index) {
        temp = ele[index];
        for (j = index; j >= inc; j -= inc)
          if (ele[j - inc] > temp)
            ele[j] = ele[j - inc];
          else
            break;
        ele[j] = temp;
      }
      if (inc == 1) break;
    }
  }

  void insertsort(vector<int> &ele) {
    int temp = 0, j = 0;
    for (int index = 1; index < ele.size(); ++index) {
      temp = ele[index];
      for (j = index; j >= 1 && temp < ele[j - 1]; --j) ele[j] = ele[j - 1];
      ele[j] = temp;
    }
  }

 private:
  vector<int> Sedgewick{1,         5,         19,        41,       109,
                        209,       505,       929,       2161,     3905,
                        8929,      16001,     36289,     64769,    146305,
                        260609,    587521,    1045505,   2354689,  4188161,
                        9427969,   16764929,  37730305,  67084289, 150958081,
                        268386305, 603906049, 1073643521};
  vector<int> Hibbard{1,        3,         7,         15,        31,
                      63,       127,       255,       511,       1023,
                      2047,     4095,      8191,      16383,     32767,
                      65535,    131071,    262143,    524287,    1048575,
                      2097151,  4194303,   8388607,   16777215,  33554431,
                      67108863, 134217727, 268435455, 536870911, 1073741823};
};

void test() {
  sort solution;
  vector<int> test;
  default_random_engine e(time(0));
  uniform_int_distribution<unsigned> u(0, TEST);
  for (int i = 0; i < TEST; ++i) {
    test.push_back(u(e));
  }
  solution.shellsort(test, "Shell");
  int prev = 0;
  for (int index = 0; index < TEST; ++index) {
    if (prev > test[index]) cout << "error" << endl;
    prev = test[index];
  }
  vector<int> test2;
  for (int i = 0; i < TEST; ++i) {
    test2.push_back(u(e));
  }
  solution.insertsort(test2);
  prev = 0;
  for (int index = 0; index < TEST; ++index) {
    if (prev > test2[index]) cout << "error" << endl;
    prev = test2[index];
  }
}

int main() {
  test();
  return 0;
}