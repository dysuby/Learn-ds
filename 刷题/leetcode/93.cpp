void backtrack(string s, int index, vector<string> &ans, int left) {
  int size = s.size();
  string each;
  int temp;
  cout << s << " " << temp << " " << left << endl;
  if (!left && (index == size || size - index > 3 ||
                s[index] == '0' && size - index > 1 ||
                stoi(s.substr(index, size)) > 255)) {
    return;
  } else if (!left) {
    ans.push_back(s);
  } else if (s[index] == '0') {
    each = s.substr(0, index + 1) + "." + s.substr(index + 1, size);
    backtrack(each, index + 2, ans, left - 1);
  } else {
    for (int i = index; i < size && i - index < 3; ++i) {
      temp = stoi(s.substr(index, i - index + 1));
      cout << temp << endl;
      if (temp <= 255 && !(temp == 0 && i != index)) {
        each = s.substr(0, i + 1) + "." + s.substr(i + 1, size);
        backtrack(each, i + 2, ans, left - 1);
      }
    }
  }
}

class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    if (s.size() <= 3) return ans;
    backtrack(s, 0, ans, 3);
    return ans;
  }
};

// class Solution {
//  public:
//   vector<string> restoreIpAddresses(string s) {
//     vector<string> res;
//     int len = s.size();
//     for (int i = 1; i < 4 && i < len - 2; i++) {
//       for (int j = i + 1; j < i + 4 && j < len - 1; j++) {
//         for (int k = j + 1; k < j + 4 && k < len; k++) {
//           if (len - k > 3) continue;
//           string a = s.substr(0, i);
//           string b = s.substr(i, j - i);
//           string c = s.substr(j, k - j);
//           string d = s.substr(k, len - k);
//           if (isValid(a) && isValid(b) && isValid(c) && isValid(d))
//             res.push_back(a + '.' + b + '.' + c + '.' + d);
//         }
//       }
//     }
//     return res;
//   }
//   bool isValid(string s) {
//     if (atoi(s.c_str()) > 255 || s[0] == '0' && s.size() > 1) return false;
//     return true;
//   }
// };