class Solution {
 public:
  int minSteps(int n) {
    if (n == 1) return 0;
    int count = 0, i;
    for (i = 2; n % i; ++i) {}
    count += i;
    return count + minSteps(n / i);
  }
};  