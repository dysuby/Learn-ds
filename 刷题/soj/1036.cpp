int print(Node* head) {
  Node *cur = head;
  while (cur) {
    cout << cur->data << " ";
    cur = cur->next;
  }
  cout << endl;
  return 0;
}