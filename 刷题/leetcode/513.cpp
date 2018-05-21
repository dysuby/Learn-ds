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
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (q.size()) {
      root = q.front();
      if (root->right) q.push(root->right);
      if (root->left) q.push(root->left);
      q.pop();
    }
    return root->val;
  }
};