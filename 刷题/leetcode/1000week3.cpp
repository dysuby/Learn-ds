#include <stack>

using std::stack;

class Queue {
 public:
  bool IsEmpty() const { return firstStack.empty(); }

  int &front() { return firstStack.top(); }

  void push(int a) {
    while (firstStack.size()) {
      int top = firstStack.top();
      secondStack.push(top);
      firstStack.pop();
    }
    firstStack.push(a);
    while (secondStack.size()) {
      int top = secondStack.top();
      firstStack.push(top);
      secondStack.pop();
    }
  }

  void pop() {
    if (!IsEmpty()) firstStack.pop();
  }

 private:
  stack<int> firstStack;

  stack<int> secondStack;
};
