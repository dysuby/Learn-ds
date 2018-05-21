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
  void dfs(TreeNode* root, int num, int& sum) {
    if (!root) return;
    num = num * 10 + root->val;
    if (!root->left && !root->right) {
      sum = sum + num;
      return;
    }
    dfs(root->left, num, sum);
    dfs(root->right, num, sum);
  }
  int sumNumbers(TreeNode* root) {
    if (!root) return 0;
    int sum = 0;
    dfs(root, 0, sum);
    return sum;
  }
};