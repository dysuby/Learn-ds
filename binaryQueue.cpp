#include <cstring>
#include <iostream>
#include <vector>
#define MAX (32)
#define MIN (~0 ^ (1 << 31))
using namespace std;

class binaryQueue {
 private:
  struct node {
    int ele;
    node* sibling;
    node* child;
    node(int i, node* s = 0, node* c = 0) : ele(i), sibling(s), child(c) {}
    ~node() {
      if (sibling) delete sibling;
      if (child) delete child;
    }
  };

  int _size;
  node* roots[MAX];

  node* mergeSame(node* left, node* right) {
    if (right->ele < left->ele) return mergeSame(right, left);
    right->sibling = left->child;
    left->child = right;
    return left;
  }

 public:
  binaryQueue() : _size(0) { memset(roots, 0, MAX * sizeof(binaryQueue*)); }

  ~binaryQueue() { clear(); }

  binaryQueue& push(int e) {
    node* newNode = new node(e);
    binaryQueue temp;
    temp.roots[0] = newNode;
    ++temp._size;
    merge(temp);
    return *this;
  }

  binaryQueue& merge(binaryQueue& heap) {
    if (heap._size + this->_size > MIN) {
      cout << "Error!";
      return *this;
    }
    node *T1(0), *T2(0), *carry(0);
    int i(0), j(1);
    _size += heap._size;
    for (; j <= _size; j *= 2, ++i) {
      T1 = roots[i], T2 = heap.roots[i];
      switch (!!T1 + !!T2 * 2 + !!carry * 4) {
        case 0:  // no trees
        case 1:  // only T1
          break;
        case 2:  // only T2
          roots[i] = T2;
          heap.roots[i] = 0;
          break;
        case 3:  // T1 and T2
          carry = mergeSame(T1, T2);
          roots[i] = 0;
          heap.roots[i] = 0;
          break;
        case 4:  // only carry
          roots[i] = carry;
          carry = 0;
          break;
        case 5:  // T1 and carry
          carry = mergeSame(T1, carry);
          roots[i] = 0;
          break;
        case 6:  // T2 and carry
          carry = mergeSame(T2, carry);
          heap.roots[i] = 0;
          break;
        case 7:  // all
          roots[i] = carry;
          carry = mergeSame(T1, T2);
          heap.roots[i] = 0;
          break;
      }
    }
    return *this;
  }

  int pop() {
    if (_size == 0) return -1;
    int index = 0, min = MIN;
    for (int i = 0, j = 1; j <= _size; ++i, j *= 2)
      if (roots[i] && roots[i]->ele < min) {
        index = i;
        min = roots[i]->ele;
      }
    node* deletedNode = roots[index];
    node* children = roots[index]->child;
    roots[index]->child = 0;
    delete roots[index];
    roots[index] = 0;
    binaryQueue deletedHeap;
    deletedHeap._size = (1 << index) - 1;
    for (int i = index - 1; i >= 0; --i) {
      deletedHeap.roots[i] = children;
      children = children->sibling;
      deletedHeap.roots[i]->sibling = 0;
    }
    roots[index] = 0;
    _size -= (deletedHeap._size + 1);
    merge(deletedHeap);
    return min;
  }

  int size() { return _size; }

  void clear() {
    for (int i = 0, j = 1; j <= _size; j *= 2, ++i) {
      if (roots[i]) delete roots[i];
    }
  }

  int top() {
    if (_size == 0) return -1;
    int index = 0, min = MIN;
    for (int i = 0, j = 1; j <= _size; ++i, j *= 2)
      if (roots[i] && roots[i]->ele < min) {
        index = i;
        min = roots[i]->ele;
      }
    return min;
  }
};

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    binaryQueue h;
    for (int i = 0; i < lists.size(); ++i) {
      binaryQueue tempHeap;
      ListNode* temp = lists[i];
      while (temp) {
        tempHeap.push(temp->val);
        temp = temp->next;
      }
      h.merge(tempHeap);
    }
    if (h.size() == 0) return 0;
    ListNode* res = new ListNode(h.pop());
    ListNode* temp = res;
    while (h.size() != 0) {
      temp->next = new ListNode(h.pop());
      temp = temp->next;
    }
    return res;
  }
};

int main() {
  // vector<ListNode*> test;
  // vector<vector<int>>
  // arr({{-8,2,4},{-9,-9,-9,-9,-8,-5,-3,-2,1},{-9,-7,-5,-3,-3,-1,0,3,4},{-9,-7,-6,-4,-2,-1,3,4},{-10,-3,0},{-9,0,4},{-8,-8}});
  // for (int index = 0; index < arr.size(); ++index) {
  //   ListNode *one = new ListNode(arr[index][0]);
  //   ListNode *temp = one;
  //   for (int j = 1; j < arr[index].size(); ++j) {
  //     temp -> next = new ListNode(arr[index][j]);
  //     temp = temp -> next;
  //   }
  //   test.push_back(one);
  // }
  // Solution sol;
  // ListNode* temp = sol.mergeKLists(test);
  // while (temp) {
  //   cout << temp -> val << " ";
  //   temp = temp -> next;
  // }
  return 0;
}