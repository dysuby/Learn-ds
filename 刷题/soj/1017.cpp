#include <iostream>
#include <vector>
using namespace std;

struct node {
  node *left, *right;
  int i;
  node(int j, node *l = 0, node *r = 0) : i(j), left(l), right(r) {}
  ~node() {
    delete left;
    delete right;
  }
};

node *BuildTree(int ps, int pe, int is, int ie, vector<int> in,
                vector<int> pre) {
  if (ps >= pe || is >= ie) return 0;
  int index = is;
  for (; index < ie; ++index)
    if (in[index] == pre[ps]) break;
  node *t = new node(pre[ps]);
  if (index > is)
    t->left = BuildTree(ps + 1, ps + index - is + 1, is, index, in, pre);
  if (index < ie - 1)
    t->right = BuildTree(ps + index - is + 1, pe, index + 1, ie, in, pre);
  return t;
}

int height(node *root) {
  if (root) {
    int h = height(root->left) > height(root->right) ? height(root->left) + 1
                                                     : height(root->right) + 1;
    return h;
  } else {
    return -1;
  }
}

// void post(node *root) {
//   if (root) {
//     post(root->left);
//     post(root->right);
//     cout << root->i << " ";
//   }
// }

int main() {
  int n, m;
  cin >> n;
  while (n--) {
    cin >> m;
    if (!m) {
      cout << -1 << endl;
      continue;
    }
    vector<int> pre(m), in(m);
    for (int i = 0; i < m; ++i) cin >> pre[i];
    for (int i = 0; i < m; ++i) cin >> in[i];
    node *root = BuildTree(0, m, 0, m, in, pre);
    // post(root);
    cout << height(root) << endl;
    delete root;
  }
  return 0;
}