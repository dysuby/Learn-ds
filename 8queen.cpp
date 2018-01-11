#include <iostream>

#define MAX_SIZE 30

using namespace std;

class queen {
 private:
  int board;
  int count;
  int pos[MAX_SIZE];
  bool column[MAX_SIZE];
  bool left[2 * MAX_SIZE - 1];
  bool right[2 * MAX_SIZE - 1];

 public:
  int time;
  queen(int b) : board(b), count(0), time(0) {
    for (int i = 0; i < 2 * MAX_SIZE - 1; ++i) {
      if (i < board) {
        pos[i] = 0;
        column[i] = true;
      }
      left[i] = true;
      right[i] = true;
    }
  }
  int getBoard() { return board; }
  bool valid(int col) {
    return column[col] && left[count - col + board - 1] && right[col + count];
  }
  bool insert(int col) {
    pos[count] = col;
    column[col] = false;
    left[count - col + board - 1] = false;
    right[col + count] = false;
    ++count;
  }
  bool remove(int col) {
    --count;
    column[col] = true;
    left[count - col + board - 1] = true;
    right[col + count] = true;
  }
  void print() {
    for (int i = 0; i < board; ++i) {
      cout << i << " " << pos[i] << endl;
    }
    cout << endl;
    ++time;
  }
  bool isSolved() {
    if (count == board) return true;
    return false;
  }
};

void solve(queen q) {
  if (q.isSolved()) {
    q.print();
  } else {
    for (int i = 0; i < q.getBoard(); ++i) {
      if (q.valid(i)) {
        q.insert(i);
        solve(q);
        q.remove(i);
      }
    }
  }
}

int main() {
  int board;
  cin >> board;
  queen q(board);
  solve(q);
  return 0;
}