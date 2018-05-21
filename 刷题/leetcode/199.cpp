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
  vector<int> rightSideView(TreeNode* root) {
    if (!root) return vector<int>();
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);
    while (q.size()) {
      int size = q.size();
      while (size) {
        TreeNode* cur = q.front();
        q.pop();
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
        if (--size == 0) ans.push_back(cur -> val);
      }
    }
    return ans;
  }
};