#include <iostream>

using namespace std;

typedef int T;
struct BinaryNode {
  T data;  // store data
  BinaryNode *left, *right;
  BinaryNode(T d, BinaryNode* l = 0, BinaryNode* r = 0)
      : data(d), left(l), right(r){};
  ~BinaryNode() {
    delete left;
    delete right;
  }
};

void preorder(const BinaryNode* root, int path, int& sum, int& size) {
  if (root) {
    sum += path;
    ++size;
    preorder(root->left, path + 1, sum, size);
    preorder(root->right, path + 1, sum, size);
  }
}

int externalPL(const BinaryNode* root) {
  int sum = 0, size = 0;
  preorder(root, 0, sum, size);
  sum += 2 * size;
  return sum;
}

int main() {
  BinaryNode* root = new BinaryNode(1);
  root->left = new BinaryNode(2);
  root->right = new BinaryNode(3);
  root->left->left = new BinaryNode(2);
  root->left->left->right = new BinaryNode(2);
  root->right->right = new BinaryNode(3);
  root->right->left = new BinaryNode(3);
  root->right->left->right = new BinaryNode(3);
  cout << externalPL(root) << endl;
  delete root;
  return 0;
}