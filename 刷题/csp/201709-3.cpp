#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> objects;
string prev;
struct Stack {
  string stack[128];
  int top;
  void push(string s) {
    stack[++top] = s;
  }
  string pop() {
    return stack[top--];
  }
};
Stack s;

void parse(string target) {
  string key = "", value = "";
  bool keyBegin = false, valueBegin = false, temp = false, flag = false;
  if (s.top != 0)
    key = s.stack[s.top] + "." + key;
  for (int i = 0; i < target.size(); ++i) {
    if (target[i] == '{')
      s.push(prev);
    else if (target[i] == '}')
      s.pop();
    else if (target[i] == '\"') {
      if (temp == false && keyBegin == false && valueBegin == false) {
        keyBegin = true;
      } else if (temp) {
        valueBegin = true;
        temp = false;
      } else if (valueBegin == true) {
        valueBegin = false;
      } else if (temp == false && keyBegin) {
        temp = true;
        keyBegin = false;
        prev = key;
      }
    } else {
        if (target[i] == '\\') {
          if (keyBegin)
            key.push_back(target[i + 1]);
          else if (valueBegin)
            value.push_back(target[i + 1]);
          ++i;
        } else {
          if (keyBegin) {
            flag = true;
            key.push_back(target[i]);
          }
          else if (valueBegin) {
            value.push_back(target[i]);
          }
        }
      }
  }
  if (flag)
    objects[key] = value;
}

int main() {
  string json;
  s.top = -1;
  int n, m;
  cin >> n >> m;
  while (cin.peek() != '{')
    cin.get();
  for (int i = 0; i < n; ++i) {
    getline(cin, json);
    parse(json);
  }
  string target;
  for (int i = 0; i < m; ++i) {
    cin >> target;
    if (objects.find(target) == objects.end()) {
      cout << "NOTEXIST"  << endl;
      continue;
    }
    if (objects[target] == "")
      cout << "OBJECT" << endl;
    else
      cout << "STRING " << objects[target] << endl;
  }
  return 0;
}