#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

#define MAX_SIZE 100
#define EMPTY -1
using namespace std;

class Stack {
 private:
  string sta[MAX_SIZE];
  int topEle;

 public:
  Stack() { topEle = EMPTY; }
  string pop() {
    if (topEle != EMPTY)
      return sta[topEle--];
    else
      return "";
  }
  void push(string i) {
    if (topEle != MAX_SIZE - 1) sta[++topEle] = i;
  }
  string top() {
    if (topEle != EMPTY) return sta[topEle];
  }
  bool isEmpty() { return topEle == EMPTY; }
};

int stoi(string str) {
  int num = 0, i = 0;
  if (str[0] == '-') ++i;
  for (; i < str.length(); ++i) {
    num = num * 10 + str[i] - '0';
  }
  if (str[0] == '-') num = -num;
  return num;
}

string getResult(string postfix[], int size) {
  Stack data;
  char num[MAX_SIZE];
  memset(num, 0, MAX_SIZE * sizeof(char));
  for (int i = 0; i < size; ++i) {
    if (postfix[i] == "+") {
      int right = stoi(data.pop());
      int left = stoi(data.pop());
      sprintf(num, "%d", left + right);
      data.push(string(num));
    } else if (postfix[i] == "-") {
      int right = stoi(data.pop());
      int left = stoi(data.pop());
      sprintf(num, "%d", left - right);
      data.push(string(num));
    } else if (postfix[i] == "/") {
      int right = stoi(data.pop());
      int left = stoi(data.pop());
      sprintf(num, "%d", left / right);
      data.push(string(num));
    } else if (postfix[i] == "*") {
      int right = stoi(data.pop());
      int left = stoi(data.pop());
      sprintf(num, "%d", left * right);
      data.push(string(num));
    } else {
      data.push(postfix[i]);
    }
    memset(num, 0, MAX_SIZE * sizeof(char));
  }
  return data.pop();
}

string compute(string tar) {
  string postfix[MAX_SIZE];
  Stack operation;
  string num("");
  string empty("");
  int pos(0);
  for (int i = 0; i < tar.length(); ++i) {
    if (tar[i] <= '9' && tar[i] >= '0') {
      num.push_back(tar[i]);
    } else {
      if (num != "") {
        postfix[pos++] = num;
        num = "";
      } else if (tar[i] == '-') {
        postfix[pos++] = "0";
      }
      if (tar[i] == '+' || tar[i] == '-') {
        while (!operation.isEmpty() && operation.top() != "(")
          postfix[pos++] = operation.pop();
        empty.push_back(tar[i]);
        operation.push(empty);
      } else if (tar[i] == '*' || tar[i] == '/') {
        while (!operation.isEmpty() && operation.top() != "(" &&
               operation.top() != "+" && operation.top() != "-")
          postfix[pos++] = operation.pop();
        empty.push_back(tar[i]);
        operation.push(empty);
      } else if (tar[i] == '(') {
        empty.push_back(tar[i]);
        operation.push(empty);
      } else if (tar[i] == ')') {
        while (!operation.isEmpty() && operation.top() != "(")
          postfix[pos++] = operation.pop();
        operation.pop();
      }
      empty = "";
    }
  }
  if (num != "") postfix[pos++] = num;
  while (!operation.isEmpty()) postfix[pos++] = operation.pop();
  return getResult(postfix, pos);
}

int main() {
  string tar;
  while (cin >> tar) {
    if (tar == "q") break;
    cout << compute(tar) << endl;
    tar = "";
  }
  return 0;
}
