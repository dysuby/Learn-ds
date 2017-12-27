/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head -> next)
            return;
        ListNode *temp = head;
        vector<ListNode*> nodes;
        while (temp) {
            nodes.push_back(temp);
            temp = temp -> next;
        }
        for (int i = 0, j = nodes.size() - 1; i < j; ++i, --j) {
            if (j - i == 1)
                break;
            nodes[j] -> next = nodes[i] -> next;
            nodes[i] -> next = nodes[j];
            nodes[j - 1] -> next = 0;
        }
    }
};