class Solution {
 public:
  int hammingDistance(int x, int y) {
    int ans = x ^ y;
    int dif = 0;
    while (ans) {
      dif += ans & 1;
      ans >>= 1;
    }
    return dif;
  }
};