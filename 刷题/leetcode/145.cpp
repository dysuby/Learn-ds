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
  vector<int> postorderTraversal(TreeNode *root) {
    stack<TreeNode *> nodes;
    map<TreeNode *, int> visit;
    vector<int> ans;
    if (root == 0) return ans;
    nodes.push(root);
    while (nodes.size()) {
      TreeNode *temp = nodes.top();
      if (temp->right && visit[temp->right] == 0) {
        nodes.push(temp->right);
        if (!temp->left) continue;
      }
      if (temp->left && visit[temp->left] == 0) {
        nodes.push(temp->left);
        continue;
      }
      ans.push_back(temp->val);
      ++visit[temp];
      nodes.pop();
    }
    return ans;
  }
};

// class Solution {
//  public:
//   vector<int> postorderTraversal(TreeNode *root) {
//     stack<TreeNode *> nodeStack;
//     vector<int> result;
//     // base case
//     if (root == NULL) return result;
//     nodeStack.push(root);
//     while (!nodeStack.empty()) {
//       TreeNode *node = nodeStack.top();
//       result.push_back(node->val);
//       nodeStack.pop();
//       if (node->left) nodeStack.push(node->left);
//       if (node->right) nodeStack.push(node->right);
//     }
//     reverse(result.begin(), result.end());
//     return result;
//   }
// };