template <typename E>

class LinkedList {
 private:
  // inner class: linked-list node
  class Node {
   public:
    E data;
    Node* next;
  };

  Node* first;

 public:
  LinkedList() { first = 0; }

  ~LinkedList() {
    while (first != 0) {
      removeFirst();
    }
  }

  E getFirst() const { return first->data; }

  bool isEmpty() const { return first == 0; }

  LinkedList(const LinkedList& that);
  LinkedList& operator=(const LinkedList& that);
  void removeFirst();
  void addFirst(E data);
};

template <typename E>
LinkedList<E>::LinkedList(const LinkedList& that) : first(0) {
  *this = that;
}

template <typename E>
LinkedList<E>& LinkedList<E>::operator=(const LinkedList& that) {
  while (first) {
    Node* temp = first->next;
    delete first;
    first = temp;
  }
  if (!that.first) return *this;
  Node* old = that.first;
  first = new Node;
  first->data = old->data;
  Node* temp = first;
  old = old->next;
  while (old) {
    temp->next = new Node;
    temp = temp->next;
    temp->data = old->data;
    old = old->next;
  }
  temp->next = 0;
  return *this;
}

template <typename E>
void LinkedList<E>::removeFirst() {
  if (!first) return;
  Node* temp = first->next;
  delete first;
  first = temp;
}

template <typename E>
void LinkedList<E>::addFirst(E data) {
  Node* temp = new Node;
  temp->data = data;
  temp->next = first;
  first = temp;
}

#include <iostream>
using namespace std;
int main() {
  LinkedList<int> test, t2;
  test.addFirst(1);
  t2 = test;
  LinkedList<int> t3(t2);
  cout << t3.getFirst();
  return 0;
}