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
  vector<int> largestValues(TreeNode* root) {
    if (!root) return vector<int>();
    vector<int> ans;
    queue<TreeNode*> q, next;
    q.push(root);
    int max = INT_MIN;
    while (q.size()) {
      TreeNode* cur = q.front();
      q.pop();
      max = cur->val > max ? cur->val : max;
      if (cur->left) next.push(cur->left);
      if (cur->right) next.push(cur->right);
      if (q.empty()) {
        q = next;
        next = queue<TreeNode*>();
        ans.push_back(max);
        max = INT_MIN;
      }
    }
    return ans;
  }
};