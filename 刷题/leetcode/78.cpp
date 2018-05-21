class Solution {
 public:
  void back(vector<int> sub, vector<vector<int>> &ans, int index, int size,
            vector<int> nums) {
    if (index == size) {
      ans.push_back(sub);
      return;
    }
    back(sub, ans, index + 1, size, nums);
    sub.push_back(nums[index]);
    back(sub, ans, index + 1, size, nums);
  }

  vector<vector<int>> subsets(vector<int> &nums) {
    int size = nums.size();
    if (size == 0) return vector<vector<int>>();
    vector<vector<int>> ans;
    vector<int> each;
    back(each, ans, 0, size, nums);
    return ans;
  }
};