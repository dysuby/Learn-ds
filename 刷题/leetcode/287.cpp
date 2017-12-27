class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int lo = 1, up = nums.size() - 1, mid, count;
    while (lo < up) {
      mid = (lo + up) / 2;
      count = 0;
      for (auto i : nums)
        if (i <= mid) ++count;
      if (count <= mid)
        lo = mid + 1;
      else
        up = mid;
    }
    return lo;
  }
};

// hao JB diao
// class Solution {
//  public:
//   int findDuplicate(vector<int>& nums) {
//     for (int i = 0; i < nums.size(); i++) {
//       if (nums[abs(nums[i])] < 0) {
//         return abs(nums[i]);
//       } else {
//         nums[abs(nums[i])] *= -1;
//       }
//     }
//   }
// };