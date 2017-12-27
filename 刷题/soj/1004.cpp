#include <list>
#include <vector>
using namespace std;

bool isPrime(int n) {
  if (n == 2 || n == 3) return true;
  if (n == 1 || n % 2 == 0) return false;
  for (int i = 3; i * i <= n; i += 2)
    if (n % i == 0) return false;
  return true;
}

int nextPrime(int n) {
  if (n % 2 == 0) n++;
  for (; !isPrime(n); n += 2) {
  }
  return n;
}

template <typename HashedObj>
class HashTable {
 public:
  HashTable(int (*h)(HashedObj x), int size = 101) : currentSize(0), yyyhash(h) {
    theLists.resize(size);
  }

  bool contains(const HashedObj& x) const  // If x is in the table, it returns
                                           // true, otherwise, it returns false.
  {
    int hashVal = myhash(x);
    for (auto i = theLists[hashVal].begin(); i != theLists[hashVal].end(); ++i)
      if (*i == x) return true;
    return false;
  }

  void makeEmpty() {
    for (int i = 0; i < theLists.size(); i++) theLists[i].clear();
  }

  bool insert(const HashedObj& x)
  // Insert key x  if x is not in the table and return true. Otherwise, return
  // false and do nothing.  If the table is full, you will call rehash.
  {
    if (!contains(x)) return false;
    if (currentSize == theLists.size()) rehash();
    int pos = myhash(x);
    theLists[pos].push_back(x);
    if (theLists[pos].size() == 1) ++currentSize;
    return true;
  }

  bool remove(const HashedObj& x)
  // If x is present in the table, remove it and return true. Otherwise, return
  // false.
  {
    if (!contains(x)) return false;
    int pos = myhash(x);
    auto i = theLists[pos].begin();
    for (; *i != x; ++i) {
    }
    theLists[pos].erase(i);
    if (!theLists[pos].size()) --currentSize;
    return true;
  }

 private:
  vector<list<HashedObj> > theLists;  // The array of Lists
  int currentSize;
  int (*yyyhash)(HashedObj x);  // yyyhash function

  int myhash(const HashedObj& x) const {
    int hashVal = yyyhash(x);
    hashVal %= theLists.size();
    if (hashVal < 0) hashVal += theLists.size();
    return hashVal;
  }

  void rehash() {
    vector<list<HashedObj> > oldLists = theLists;
    // Create new double-sized, empty table
    theLists.resize(nextPrime(2 * theLists.size()));
    for (int j = 0; j < theLists.size(); j++) theLists[j].clear();
    // Copy table over
    currentSize = 0;
    for (int i = 0; i < oldLists.size(); i++) {
      auto itr = oldLists[i].begin();
      while (itr != oldLists[i].end()) insert(*itr++);
    }
  }
};

int main() {
  return 0;
}