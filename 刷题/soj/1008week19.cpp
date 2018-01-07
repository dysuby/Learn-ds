#include <iostream>
#include <algorithm>
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

int height(node *root) {
  if (!root) return -1;
  return max(height(root->left), height(root->right)) + 1;
}

int main() {
  int n, m, num;
  cin >> n;
  while (n--) {
    cin >> m;
    cin >> num;
    node *root = new node(num);
    while (--m) {
      cin >> num;
      insert(num, root);
    }
    cout << height(root) << endl;
    delete root;
  }
  return 0;
}