class Solution {
 public:
  int trap(vector<int>& height) {
    stack<int> s;
    int ans = 0;
    for (int index = 0; index < height.size(); ++index) {
      while (s.size() && height[index] > height[s.top()]) {
        int i = s.top();
        s.pop();
        if (s.empty()) continue;
        int distance = index - s.top() - 1;
        ans += ((height[index] < height[s.top()] ? height[index]
                                                 : height[s.top()]) -
                height[i]) *
               distance;
      }
      s.push(index);
    }
    return ans;
  }
};