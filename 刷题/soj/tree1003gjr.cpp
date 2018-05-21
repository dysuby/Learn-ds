#include <stack>
using namespace std;

// root is a pointer to the root of the binary tree.
template <typename T>
void inorder_recursive(BinaryNode<T>* root, void (*visit)(T& x)) {
  if (root) {
    inorder_recursive(root->left, visit);
    visit(root->elem);
    inorder_recursive(root->right, visit);
  }
}

// root is a pointer to the root of the binary tree.
template <typename T>
void inorder(BinaryNode<T>* root, void (*visit)(T& x)) {
  if (!root) return;
  stack<BinaryNode<T>*> q;
  BinaryNode<T>* cur = root;
  while (cur || q.size()) {
    while (cur) {
      q.push(cur);
      cur = cur->left;
    }
    cur = q.top();
    q.pop();
    visit(cur->elem);
    cur = cur->right;
  }
}