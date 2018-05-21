#include <iostream>
#include <string>
using namespace std;
struct Node {
  string prizeItem;
  Node *next;
};

class HashTable {
  // poiter point to the hash table
  Node **tabelPtr;
  // the size of the hash table
  int size;

 public:
  HashTable(int num);
  ~HashTable();
  // Check if the prize item already in the hash table
  bool isAdded(int SID, string prizeItem);
  // Add a prize item to the hash table
  void addItem(int SID, string prizeItem);
  void showItems(int SID);
};

HashTable::HashTable(int num) : size(num) {
  tabelPtr = new Node *[num];
  for (int i = 0; i < num; ++i) tabelPtr[i] = 0;
}

HashTable::~HashTable() {
  Node *temp = 0;
  for (int i = 0; i < size; ++i) {
    while (tabelPtr[i]) {
      temp = tabelPtr[i]->next;
      delete tabelPtr[i];
      tabelPtr[i] = temp;
    }
  }
  delete[] tabelPtr;
}

// Check if the prize item already in the hash table
bool HashTable::isAdded(int SID, string prizeItem) {
  Node *temp = tabelPtr[SID];
  while (temp) {
    if (temp->prizeItem == prizeItem) return true;
    temp = temp->next;
  }
  return false;
}

// Add a prize item to the hash table
void HashTable::addItem(int SID, string prizeItem) {
  if (isAdded(SID, prizeItem)) return;
  Node *temp = new Node;
  temp->next = tabelPtr[SID];
  temp->prizeItem = prizeItem;
  tabelPtr[SID] = temp;
}

void HashTable::showItems(int SID) {
  if (!tabelPtr[SID]) {
    cout << "None\n";
    return;
  }
  cout << SID << ": ";
  Node *temp = tabelPtr[SID];
  while (temp) {
    cout << temp->prizeItem << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  int n, m, id;
  string s;
  cin >> n >> m;
  HashTable fuck(n);
  while (n--) {
    cin >> id >> s;
    fuck.addItem(id, s);
  }
  while (m--) {
    cin >> id;
    fuck.showItems(id);
    cout << endl;
  }
  return 0;
}