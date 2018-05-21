#include <iostream>
#include <string>
using namespace std;

struct node {
  char val;
  node *left, *right;
  node(char v, node *l = 0, node *r = 0) : val(v), left(l), right(r) {}
  ~node() {
    delete left;
    delete right;
  }
};

node *build(string pre, string in, int ps, int pe, int is, int ie) {
  if (ps >= pe || is >= ie) return 0;
  node *root = new node(pre[ps]);
  int i = is;
  while (in[i] != pre[ps]) ++i;
  root->left = build(pre, in, ps + 1, ps + i - is + 1, is, i);
  root->right = build(pre, in, ps + i - is + 1, pe, i + 1, ie);
  return root;
}

void postorder(node *root, string &ans) {
  if (root) {
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans += root->val;
  }
}

int main() {
  string pre, in, ans;
  cin >> pre >> in;
  node *root = build(pre, in, 0, pre.size(), 0, pre.size());
  postorder(root, ans);
  cout << ans << endl;
  delete root;
  return 0;
}