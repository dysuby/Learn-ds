class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int size = nums.size();
    vector<int> ans(2);
    map<int, int> m;
    for (int i = 0; i < size; ++i) {
      if (m.find(nums[i]) != m.end()) {
        int pos = (m.find(nums[i]))->second;
        if (pos != i) {
          ans[0] = pos;
          ans[1] = i;
          return ans;
        }
      } else {
        m[target - nums[i]] = i;
      }
    }
    return ans;
  }
};