/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    if (root == 0) return true;
    TreeNode *right = root->right, *left = root->left;
    if (right && right->val <= root->val) return false;
    if (left && left->val >= root->val) return false;
    if (right)
      while (right->left) {
        if (right->left->val <= root->val) return false;
        right = right->left;
      }
    if (left)
      while (left->right) {
        if (left->right->val >= root->val) return false;
        left = left->right;
      }
    return isValidBST(root->left) && isValidBST(root->right);
  }
};