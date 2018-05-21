#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node {
  node *left, *right;
  int e;
  // bool operator<(const node *n) { return this->e < n->e; }
  node(int i, node *l = 0, node *r = 0) : e(i), left(l), right(r) {}
  ~node() {
    delete left;
    delete right;
  }
};

bool cmp(const node *a, const node *b) { return a->e < b->e; }

void preorder(node *root, int depth, int &sum) {
  if (root) {
    if (!root->left && !root->right) sum += root->e * depth;
    preorder(root->left, depth + 1, sum);
    preorder(root->right, depth + 1, sum);
  }
}

int main() {
  int n, each, sum;
  cin >> n;
  while (n--) {
    vector<node *> ans;
    while (cin >> each && each != 0) ans.push_back(new node(each));
    if (ans.empty()) continue;
    while (ans.size() != 1) {
      sort(ans.begin(), ans.end(), cmp);
      node *left = ans[0];
      ans.erase(ans.begin());
      node *right = ans[0];
      ans.erase(ans.begin());
      node *father = new node(left->e + right->e, left, right);
      ans.push_back(father);
    }
    sum = 0;
    node *root = ans[0];
    preorder(root, 0, sum);
    delete root;
    cout << sum << endl;
  }
  return 0;
}