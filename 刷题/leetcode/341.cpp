/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
typedef NestedInteger ni;
class NestedIterator {
  stack<ni> it;
  int n;

 public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for (int i = nestedList.size() - 1; i >= 0; --i) it.push(nestedList[i]);
  }

  int next() { return n; }

  bool hasNext() {
    ni next;
    while (it.size()) {
      next = it.top();
      it.pop();
      if (next.isInteger()) {
        n = next.getInteger();
        return true;
      }
      vector<ni> each = next.getList();
      for (int i = each.size() - 1; i >= 0; --i) it.push(each[i]);
    }
    return false;
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */