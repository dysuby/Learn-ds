class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int size = nums.size();
    if (!size) return 0;
    int prev(nums[0]), ans = nums[0];
    for (int i = 1; i < size; ++i) {
      if (prev < 0)
        prev = nums[i];
      else
        prev += nums[i];
      ans = max(prev, ans);
    }
    return ans;
  }
};