/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// #define MAX (32)
// #define MIN (~0 ^ (1 << 31))
// class binaryHeap {
//   private:
//     struct node {
//       int ele;
//       node *sibling;
//       node *child;
//       node(int i, node* s = 0, node* c = 0): ele(i), sibling(s), child(c) {}
//       ~node() {
//         if (sibling)
//           delete sibling;
//         if (child)
//           delete child;
//       }
//     };

//     int _size;
//     node* roots[MAX];

//     node* mergeSame(node *left, node *right) {
//       if (right -> ele < left -> ele)
//         return mergeSame(right, left);
//       right -> sibling = left -> child;
//       left -> child = right;
//       return left;
//     }
//   public:
//     binaryHeap(): _size(0) {
//       memset(roots, 0, MAX * sizeof(binaryHeap*));
//     }

//     ~binaryHeap() {
//       clear();
//     }

//     binaryHeap& push(int e) {
//       node *newNode = new node(e);
//       binaryHeap temp;
//       temp.roots[0] = newNode;
//       ++temp._size;
//       merge(temp);
//       return *this;
//     }

//     binaryHeap& merge(binaryHeap &heap) {
//       if (heap._size + this -> _size > MIN) {
//         cout << "Error!";
//         return *this;
//       }
//       node *T1(0), *T2(0), *carry(0);
//       int i(0), j(1);
//       _size += heap._size;
//       for ( ; j <= _size; j *= 2, ++i) {
//         T1 = roots[i], T2 = heap.roots[i];
//         switch(!!T1 + !!T2 * 2 + !!carry * 4) {
//           case 0: //no trees
//           case 1: //only T1
//             break;
//           case 2: //only T2
//             roots[i] = T2;
//             heap.roots[i] = 0;
//             break;
//           case 3: //T1 and T2
//             carry = mergeSame(T1, T2);
//             roots[i] = 0;
//             heap.roots[i] = 0;
//             break;
//           case 4: //only carry
//             roots[i] = carry;
//             carry = 0;
//             break;
//           case 5: //T1 and carry
//             carry = mergeSame(T1, carry);
//             roots[i] = 0;
//             break;
//           case 6: //T2 and carry
//             carry = mergeSame(T2, carry);
//             heap.roots[i] = 0;
//             break;
//           case 7: //all
//             roots[i] = carry;
//             carry = mergeSame(T1, T2);
//             heap.roots[i] = 0;
//             break;
//         }
//       }
//       return *this;
//     }

//     int pop() {
//       if (_size == 0)
//         return -1;
//       int index = 0, min = MIN;
//       for (int i = 0, j = 1; j <= _size; ++i, j *= 2)
//         if (roots[i] && roots[i] -> ele < min) {
//           index = i;
//           min = roots[i] -> ele;
//         }
//       node *deletedNode = roots[index];
//       node *children = roots[index] -> child;
//       roots[index] -> child = 0;
//       delete roots[index];
//       roots[index] = 0;
//       binaryHeap deletedHeap;
//       deletedHeap._size = (1 << index) - 1;
//       for (int i = index - 1; i >= 0; --i) {
//         deletedHeap.roots[i] = children;
//         children = children -> sibling;
//         deletedHeap.roots[i] -> sibling = 0;
//       }
//       roots[index] = 0;
//       _size -= (deletedHeap._size + 1);
//       merge(deletedHeap);
//       return min;
//     }

//     int size() {
//       return _size;
//     }

//     void clear() {
//       for (int i = 0, j = 1; j <= _size; j *= 2, ++i) {
//         if (roots[i])
//           delete roots[i];
//       }
//     }

//     int top() {
//       if (_size == 0)
//         return -1;
//       int index = 0, min = MIN;
//       for (int i = 0, j = 1; j <= _size; ++i, j *= 2)
//         if (roots[i] && roots[i] -> ele < min) {
//           index = i;
//           min = roots[i] -> ele;
//         }
//       return min;
//     }
// };

// class Solution {
//   public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         binaryHeap h;
//         for (int i = 0; i < lists.size(); ++i) {
//           binaryHeap tempHeap;
//           ListNode* temp = lists[i];
//           while (temp) {
//             tempHeap.push(temp -> val);
//             temp = temp -> next;
//           }
//           h.merge(tempHeap);
//         }
//         if (h.size() == 0)
//             return 0;
//         ListNode* res = new ListNode(h.pop());
//         ListNode* temp = res;
//         while (h.size() != 0) {
//           temp -> next = new ListNode(h.pop());
//           temp = temp -> next;
//         }
//         return res;
//     }
// };
class Solution {
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto comp = [](ListNode *l1, ListNode *l2) { return (l1->val > l2->val); };
    priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> heap(comp);
    for (auto l : lists) {
      if (l) {
        heap.push(l);
      }
    }
    ListNode *l_min, *fake_head = new ListNode(0);
    ListNode *node = fake_head, *head;
    while (heap.size()) {
      l_min = heap.top();
      heap.pop();
      node->next = l_min;
      node = node->next;
      if (node->next) {
        heap.push(node->next);
      }
    }
    head = fake_head->next;
    free(fake_head);
    return head;
  }
};