class Solution {
 public:
  int jump(vector<int>& nums) {
    int size = nums.size();
    if (!size) return 0;
    if (size <= 2) return size - 1;
    int count = 1, remain = nums[0], i = 1, max = nums[0], maxindex = 0;
    while (--remain >= 0 && i < size - 1) {
      maxindex = nums[i] + i > max ? i : maxindex;
      max = nums[i] + i > max ? nums[i] + i : max;
      if (remain == 0) {
        ++count;
        if (max >= size - 1) return count;
        remain = nums[maxindex];
        i = maxindex;
        max = i + nums[i];
      }
      ++i;
    }
    return count;
  }
};