int leaves(const BinaryNode* root) {
  if (!root) return 0;
  if (!root->left && !root->right) return 1;
  return leaves(root->left) + leaves(root->right);
}