typedef int T;
struct BinaryNode {
  T data;  // store data
  BinaryNode *left, *right;
  BinaryNode(T d, BinaryNode *l = NULL, BinaryNode *r = NULL)
      : data(d), left(l), right(r){};
};

void cutLeaves(BinaryNode *&root) {
  if (root) {
    if (!root -> left && !root->right) {
      delete root;
      root = 0;
    } else {
      cutLeaves(root->left);
      cutLeaves(root->right);
    }
  }
}