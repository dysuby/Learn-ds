typedef int T;
struct treeNode {
  T data;
  struct treeNode *left, *right;
  treeNode(T d, treeNode *l = 0, treeNode *r = 0)
      : data(d), left(l), right(r){};
};

void compute(const treeNode *root, int depth, int width[]) {
  if (root == 0) {
    return;
  } else {
    ++width[depth];
    compute(root -> left, depth + 1, width);
    compute(root -> right, depth + 1, width);
  }
}

int width(const treeNode *root) {
  int width[1000] = {0}, max;
  compute(root, 0, width);
  for (int i = 0; i < 1000; ++i) 
    max = width[i] > max ? width[i] : max;
  return max;
}