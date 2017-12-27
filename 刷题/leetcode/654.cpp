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
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return new TreeNode(nums[0]);
    auto i = max_element(nums.begin(), nums.end());
    vector<int> left(nums.begin(), i), right(i + 1, nums.end());
    TreeNode* node = new TreeNode(*i);
    node->left = constructMaximumBinaryTree(left);
    node->right = constructMaximumBinaryTree(right);
    return node;
  }
};