/* not ac.. */
// class Solution {
//  public:
//   vector<vector<int>> fourSum(vector<int>& nums, int target) {
//     map<int, set<int>> mp;
//     set<set<int>> ansset;
//     int size = nums.size();
//     vector<vector<int>> ans;
//     for (int i = 0; i < size; ++i) {
//       for (int j = i + 1; j < size; ++j) {
//         for (int k = j + 1; k < size; ++k) {
//           set<int> v{i, j, k};
//           mp[target - nums[i] - nums[j] - nums[k]] = v;
//         }
//       }
//     }
//     for (int i = 0; i < size; ++i) {
//       auto ite = mp.find(nums[i]);
//       if (ite != mp.end()) {
//         set<int> v = ite->second;
//         for (auto k = v.begin(); k != v.end(); ++k) {
//           int i = *k;
//         }
//         v.insert(nums[i]);
//         ansset.insert(v);
//       }
//     }
//     for (auto i : ansset) {
//       vector<int> k;
//       for (auto num : i) k.push_back(num);
//       ans.push_back(i);
//     }
//     return ans;
//   }
// };

/*  others' answer */
// class Solution {
//  public:
//   vector<vector<int>> fourSum(vector<int>& nums, int target) {
//     vector<vector<int>> total;
//     int n = nums.size();
//     if (n < 4) return total;
//     sort(nums.begin(), nums.end());
//     for (int i = 0; i < n - 3; i++) {
//       if (i > 0 && nums[i] == nums[i - 1]) continue;
//       if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
//       if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
//       continue; for (int j = i + 1; j < n - 2; j++) {
//         if (j > i + 1 && nums[j] == nums[j - 1]) continue;
//         if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
//         if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;
//         int left = j + 1, right = n - 1;
//         while (left < right) {
//           int sum = nums[left] + nums[right] + nums[i] + nums[j];
//           if (sum < target)
//             left++;
//           else if (sum > target)
//             right--;
//           else {
//             total.push_back(
//                 vector<int>{nums[i], nums[j], nums[left], nums[right]});
//             do {
//               left++;
//             } while (nums[left] == nums[left - 1] && left < right);
//             do {
//               right--;
//             } while (nums[right] == nums[right + 1] && left < right);
//           }
//         }
//       }
//     }
//     return total;
//   }
// };