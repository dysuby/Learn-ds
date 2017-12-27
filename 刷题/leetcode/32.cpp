class Solution {
 public:
  int longestValidParentheses(string s) {
    stack<int> sta;
    sta.push(-1);
    int max = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        sta.push(i);
      } else {
        sta.pop();
        if (sta.empty())
          sta.push(i);
        else
          max = (max > i - sta.top()) ? max : (i - sta.top());
      }
    }
    return max;
  }
};