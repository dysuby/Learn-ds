template <typename Node_entry>
struct Node {
  Node_entry entry;
  Node *next;
  Node();
  Node(Node_entry item, Node *add_on = 0);
  // ~Node() { delete next; }
};

template <typename Node_entry>
Node<Node_entry>::Node() {
  next = 0;
}

template <typename Node_entry>
Node<Node_entry>::Node(Node_entry item, Node *add_on) {
  entry = item;
  next = add_on;
}

template <typename T>
Node<T> *copyList(const Node<T> *head) {
  if (!head) return (Node<T>*)0;
  Node<T> *newHead = new Node<T>(head->entry);
  Node<T> *newCur = newHead;
  Node<T> *cur = head->next;
  while (cur) {
    newCur->next = new Node<T>(cur->entry);
    newCur = newCur->next;
    cur = cur->next;
  }
  return newHead;
}

// #include<iostream>
// using namespace std;
// int main() {
//   Node<int> *head = new Node<int>(1);
//   head->next = new Node<int>(2);
//   Node<int> *c = copyList((Node<int> *)0);
//   while (c) {
//     cout << c->entry;
//     c = c->next;
//   }
//   return 0;
// }