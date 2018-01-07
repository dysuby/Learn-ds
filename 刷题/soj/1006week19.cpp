#include <iostream>
using namespace std;

struct node {
  int val;
  node *left, *right;
  node(int v, node *l = 0, node *r = 0) : val(v), left(l), right(r) {}
  ~node() {
    delete left;
    delete right;
  }
};

void insert(int v, node *root) {
  node *temp = root;
  while (true) {
    if (v <= temp->val && temp->left) {
      temp = temp->left;
    } else if (v <= temp->val) {
      temp->left = new node(v);
      break;
    }
    if (v > temp->val && temp->right) {
      temp = temp->right;
    } else if (v > temp->val) {
      temp->right = new node(v);
      break;
    }
  }
}

void inorder(node *root) {
  if (root) {
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
  }
}

void preorder(node *root) {
  if (root) {
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

int main() {
  int n, num;
  while (cin >> n && n) {
    cin >> num;
    node *root = new node(num);
    while (--n) {
      cin >> num;
      insert(num, root);
    }
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    delete root;
  }
  return 0;
}