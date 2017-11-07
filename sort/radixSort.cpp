#include <iostream>
#include <queue>
#include <vector>
#define BASE 10
using namespace std;

typedef struct node {
  int ele;
  node* next;
  node(int i, node *n): ele(i), next(n) {}
} node;

class Radix {
  private:
    node *head;
    queue<node*> bucket[BASE];
    int range;
    void append(node *ele) {
      node *temp = head;
      while (temp -> next)
        temp = temp -> next;
      temp -> next = ele;
      ele -> next = 0;
    }
  public:
    Radix(vector<int> arr): head(0) {
      head = new node(0, 0);
      if (arr.size() == 0)
        return;
      int max = arr[0];
      head -> next = new node(arr[0], 0);
      node *temp = head -> next;
      for (int i = 1; i < arr.size(); ++i) {
        temp -> next = new node(arr[i], 0);
        temp = temp -> next;
        if (max < arr[i])
          max = arr[i];
      }
      range = 1;
      while (max) {
        max /= 10;
        range *= 10;
      }
    }
    void sort() {
      for (int i = 1; i <= range; i *= 10) {
        for (node *now = head -> next; now; now = now -> next) {
          bucket[(now -> ele / i) % 10].push(now);
        }
        head -> next = 0;
        for (int dig = 0; dig < BASE; ++dig) {
          while (bucket[dig].size()) {
            append(bucket[dig].front());
            bucket[dig].pop();            
          }
        }
      }
    }
    void print() {
      node *temp = head -> next;
      while (temp) {
        cout << temp -> ele << " ";
        temp = temp -> next;
      }
    }
    ~Radix() {
      node *temp = head;
      while (temp) {
        temp = temp -> next;
        delete head;
        head = temp;
      }
    }

    void test() {
      int prev = 0;
      node *current = head;
      while (current) {
        if (prev > current -> ele)
          cout << "error";
        prev = current -> ele;
        current = current -> next;
      }
    }
};

int main() {
  vector<int> test;
  default_random_engine e(time(0));
  uniform_int_distribution<unsigned> u(0, 999);
  for (int i = 0; i < 999; ++i) {
    test.push_back(u(e));
  }
  Radix solution(test);
  solution.sort();
  solution.test();
  return 0;
}