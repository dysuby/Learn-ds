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
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> pre;
    if (!root) return pre;
    stack<TreeNode*> s;
    s.push(root);
    while (s.size()) {
      TreeNode* cur = s.top();
      s.pop();
      if (cur->right) s.push(cur->right);
      if (cur->left) s.push(cur->left);
      pre.push_back(cur->val);
    }
    return pre;
  }
};