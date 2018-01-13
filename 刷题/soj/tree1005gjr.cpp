#include <queue>
using namespace std;

template <typename T>
void levelTraversal(BinaryNode<T>* root, void (*visit)(T& x)) {
  if (!root) return;
  queue<BinaryNode<T>* > q;
  q.push(root);
  while (q.size()) {
    int size = q.size();
    BinaryNode<T>* cur;
    while (size--) {
      cur = q.front();
      q.pop();
      visit(cur->elem);
      if (cur->left) q.push(cur->left);
      if (cur->right) q.push(cur->right);
    }
  }
  return;
}