class Solution {
 public:
  int findMin(vector<int>& nums) {
    int size = nums.size();
    if (nums[0] < nums[size] - 1) return nums[0];
    int low = 0, up = size - 1, mid;
    while (up - low > 1) {
      mid = (low + up) / 2;
      if (nums[low] > nums[mid])
        up = mid;
      else
        low = mid;
    }
    return nums[up];
  }
};