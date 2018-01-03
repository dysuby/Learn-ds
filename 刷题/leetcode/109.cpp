/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head) return (TreeNode *)0;
    return toBST(head, 0);
  }
  TreeNode *toBST(ListNode *head, ListNode *tail) {
    ListNode *fast = head, *slow = head;
    if (head == tail) return 0;
    while (fast != tail && fast->next != tail) {
      slow = slow->next;
      fast = fast->next->next;
    }
    TreeNode *root = new TreeNode(slow->val);
    root->left = toBST(head, slow);
    root->right =toBST(slow->next, tail);
    return root;
  }
};