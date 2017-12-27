typedef int T;
struct BinaryNode {
  T data;    // store data
  int size;  // number of nodes on the tree
  BinaryNode *left, *right;
  BinaryNode(T d, int s = 0, BinaryNode *l = NULL, BinaryNode *r = NULL)
      : data(d), size(s), left(l), right(r){};
};
void insert(BinaryNode *&root, const T &x) {
  if (!root) return;
  BinaryNode *cur = root;
  while (cur->left && cur->right) {
    ++cur->size;
    if (cur->left->size < cur->right->size)
      cur = cur->left;
    else
      cur = cur->right;
  }
  ++cur->size;
  if (cur->left)
    cur->right = new BinaryNode(x, 1);
  else
    cur->left = new BinaryNode(x, 1);
}