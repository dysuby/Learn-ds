template <typename Node_entry>
struct Node {
  Node_entry entry;
  Node *next;
  Node();
  Node(Node_entry item, Node *add_on = NULL);
};

template <typename Node_entry>
Node<Node_entry>::Node() {
  next = NULL;
}

template <typename Node_entry>
Node<Node_entry>::Node(Node_entry item, Node *add_on) {
  entry = item;
  next = add_on;
}

template <typename T>
const Node<T> *medianElement(const Node<T> *head) {
  if (!head) return head;
  const Node<T> *cur = head, *ans = head;
  while (cur->next && cur->next->next) {
    cur = cur->next->next;
    ans = ans->next;
  }
  return ans;
}