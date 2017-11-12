#include <iostream>
#include <cstring>
#include <vector>
#include <random>
#define DEFAULT_SIZE 11
#define MIN -999999
#define TEST 999

using namespace std;

class heap {
  private:
    int *data;
    int size, capacity;
    void init() {
      int current = 0, child = 0;
      for (int index = size / 2; index > 0; --index) {
        current = index;
        child = current * 2;
        int temp = data[current];
        if (child < size && data[child] > data[child + 1])
          ++child;
        while (child <= size && temp > data[child]) {
          data[current] = data[child];
          current = child;
          child = current * 2;
          if (child < size && data[child] > data[child + 1])
            ++child;
        }
        data[current] = temp;
      }
    }
  public:
    heap(int s = DEFAULT_SIZE): data(nullptr), size(0),capacity(DEFAULT_SIZE) {
      if (s <= 0)
        return;
      else
        data = new int[s];
      memset(data, 0, (s) * sizeof(int));
      data[0] = MIN;
    }
    heap(vector<int> ele): data(nullptr), size(ele.size()), capacity(ele.size() + 1) {
      if (ele.size() <= 0) 
        return;
      else
        data = new int[ele.size() + 1];
      memset(data, 0, (ele.size() + 1) * sizeof(int));
      data[0] = MIN;
      for (int index = 0; index < ele.size(); ++index) 
        data[index + 1] = ele[index];
      init();
    }
    ~heap() {
      clear();
    }
    void clear() {
      if (data)
        delete[] data;
      capacity = 0;
      size = 0;
      data = nullptr;
    }
    bool insert(int i) {
      if (size + 1 == capacity)
        resize(capacity * 2);
      ++size;
      int index = size;
      for ( ; data[index / 2] > i; index /= 2) {
        data[index] = data[index / 2];
      }
      data[index] = i;
      return true;
    }
    int deleteMin() {
      if (size == 0)
        return MIN;
      int ans = data[1], last = data[size], less = 0;
      --size;
      int index = 1;
      for ( ; index * 2 <= size; index = less) {
        less = index * 2;
        if (less != size && data[less] > data[less + 1])
          ++less;
        if (last <= data[less])
          break;
        else
          data[index] = data[less];
      }
      data[index] = last;
      return ans;
    }
    int top() {
      if (size == 0)
        return MIN;
      return data[1];
    }
    int getsize() {
      return size;
    }
    bool resize(int newCapacity) {
      if (newCapacity <= capacity)
        return false;
      int *newData = new int[newCapacity];
      memset(newData, 0, newCapacity * sizeof(int));
      for (int index = 0; index <= size; ++index) {
        newData[index] = data[index];
      }
      delete[] data;
      data = newData;
      capacity = newCapacity;
      return true;
    }
};

int main() {
  vector<int> test;
  default_random_engine e(time(0));
  uniform_int_distribution<unsigned> u(0, TEST);
  for (int i = 0; i < TEST; ++i) {
    test.push_back(u(e));
  }
  heap h1(test), h2;
  int prev = MIN;
  for (int i = 0; i < TEST; ++i) {
    h2.insert(u(e));
  }
  cout << h2.getsize();
  for (int i = 0; i < TEST; ++i) {
    int current = h1.deleteMin();
    if (current < prev)
      cout << "1" << endl;
    prev = current;
  }
  prev = 0;
  for (int i = 0; i < TEST; ++i) {
    int top = h2.top();
    int current = h2.deleteMin();
    if (current < prev || top != current)
      cout << "2" << endl;
    prev = current;
  }
  h1.resize(8888);
  cout << endl;
  return 0;
}