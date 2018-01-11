#include <iostream>

#include <algorithm>
#include <ctime>
#include <queue>
#include <random>
#include <vector>
#define TEST_SIZE 1000

using namespace std;

struct node {
  int ele;
  node *left;
  node *right;
  int height;
  node(int i, node *l, node *r, int h) : ele(i), left(l), right(r), height(h) {}
};

class avl {
 private:
  node *root;

  node *leftleft(node *T) {
    node *temp = T->left;
    T->left = temp->right;
    temp->right = T;
    T->height = ((height(T->left) > height(T->right)) ? height(T->left)
                                                      : height(T->right)) +
                1;
    temp->height =
        ((T->height > height(temp->left)) ? T->height : height(temp->left)) + 1;
    return temp;
  }
  node *rightright(node *T) {
    node *temp = T->right;
    T->right = temp->left;
    temp->left = T;
    T->height = ((height(T->left) > height(T->right)) ? height(T->left)
                                                      : height(T->right)) +
                1;
    temp->height =
        ((T->height > height(temp->right)) ? T->height : height(temp->right)) +
        1;
    return temp;
  }
  node *leftright(node *T) {
    T->left = rightright(T->left);
    return leftleft(T);
  }
  node *rightleft(node *T) {
    T->right = leftleft(T->right);
    return rightright(T);
  }
  int height(node *t) {
    if (t == 0)
      return -1;
    else
      return t->height;
  }

  node *realInsert(int i, node *T) {
    if (T == 0) {
      T = new node(i, 0, 0, 0);
    } else if (i < T->ele) {
      T->left = realInsert(i, T->left);
      if (height(T->left) - height(T->right) == 2)
        if (i < T->left->ele)
          T = leftleft(T);
        else
          T = leftright(T);
    } else if (i > T->ele) {
      T->right = realInsert(i, T->right);
      if (height(T->right) - height(T->left) == 2)
        if (i > T->right->ele)
          T = rightright(T);
        else
          T = rightleft(T);
    }
    T->height = ((height(T->left) > height(T->right)) ? height(T->left)
                                                      : height(T->right)) +
                1;
    return T;
  }

  bool realRemove(node *&T, int i) {
    if (!T) return false;
    if (i < T->ele) {
      if (realRemove(T->left, i) == false) {
        return false;
      } else if (height(T->right) - height(T->left) == 2) {
        if (height(T->right->left) <= height(T->right->right))
          T = rightright(T);
        else
          T = rightleft(T);
      } else {
        T->height = ((height(T->left) > height(T->right)) ? height(T->left)
                                                          : height(T->right)) +
                    1;
      }
    } else if (i > T->ele) {
      if (realRemove(T->right, i) == false) {
        return false;
      } else if (height(T->left) - height(T->right) == 2) {
        if (height(T->left->right) <= height(T->left->left))
          T = leftleft(T);
        else
          T = leftright(T);
      } else {
        T->height = ((height(T->left) > height(T->right)) ? height(T->left)
                                                          : height(T->right)) +
                    1;
      }
    } else {
      if (T->right && T->left) {
        node *temp = T->right;
        if (temp->left) {
          while (temp->left && temp->left->left) {
            temp = temp->left;
          }
          int key = temp->left->ele;
          node *oldT = T;
          realRemove(T, key);
          oldT->ele = key;
        } else {
          int key = temp->ele;
          node *oldT = T;
          realRemove(T, key);
          oldT->ele = key;
        }
      } else if (T->left || T->right) {
        node *temp = (T->left) ? T->left : T->right;
        delete T;
        T = temp;
      } else {
        delete T;
        T = 0;
      }
    }
    return true;
  }

 public:
  avl() : root(0) {}
  ~avl() {
    clear();
    root = 0;
  }

  void preorder(void (*fun)(node *), node *T) {
    if (T == 0) return;
    fun(T);
    preorder(fun, T->left);
    preorder(fun, T->right);
  }
  void postorder(void (*fun)(node *), node *T) {
    if (T == 0) return;
    postorder(fun, T->left);
    postorder(fun, T->right);
    fun(T);
  }
  void inorder(void (*fun)(node *), node *T) {
    if (T == 0) return;
    inorder(fun, T->left);
    fun(T);
    inorder(fun, T->right);
  }

  void clear() {
    postorder([](node *t) -> void { delete t; }, root);
  }

  void insert(int i) { root = realInsert(i, root); }
  bool remove(int i) {
    if (!root) return false;
    return realRemove(root, i);
  }

  //测试函数
  void printPreorder() {
    preorder([](node *t) -> void { cout << t->ele << " "; }, root);
  }
  void printInorder() {
    inorder([](node *t) -> void { cout << t->ele << " "; }, root);
  }
  bool check() {
    queue<node *> bfs;
    if (root == 0) return true;
    bfs.push(root);
    while (bfs.size()) {
      node *t = bfs.front();
      bfs.pop();
      if ((height(t->left) - height(t->right) >= 2) ||
          (height(t->left) - height(t->right) <= -2))
        return false;
      if ((height(t) != height(t->left) + 1) &&
          (height(t) != height(t->right) + 1))
        return false;
      if ((t->left && (t->ele < t->left->ele)) ||
          (t->right && (t->ele > t->right->ele)))
        return false;
      if (t->left) bfs.push(t->left);
      if (t->right) bfs.push(t->right);
    }
    return true;
  }
  bool isRemoved(int i, vector<int> nodes) {
    node *temp = root;
    if (root == 0) return true;
    for (int index = 0; index < nodes.size(); ++index) {
      while (temp && temp->ele != nodes[index]) {
        if (nodes[index] < temp->ele)
          temp = temp->left;
        else
          temp = temp->right;
      }
      if ((temp && temp->ele == i) || (temp == 0 && nodes[index] != i))
        return false;
      temp = root;
    }
    return true;
  }
};

int main() {
  int t, m, num;
  cin >> t;
  while (t--) {
    avl tree;
    cin >> m;
    while (m--) {
      cin >> num;
      tree.insert(num);
    }
    tree.printPreorder();
    cout << endl;
  }
  return 0;
}