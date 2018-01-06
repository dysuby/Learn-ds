// bool cmp(vector<int> &a, vector<int> &b) {
//   if (a[1] == b[1]) return a[0] < b[0];
//   return a[1] < b[1];
// }
// class Solution {
//  public:
//   int scheduleCourse(vector<vector<int>> &courses) {
//     int day = 0, size = courses.size(), longest = 0, ans = 0;
//     priority_queue<int> q;
//     if (!size) return 0;
//     sort(courses.begin(), courses.end(), cmp);
//     for (int i = 0; i < size; ++i) {
//       if (day + courses[i][0] > courses[i][1] && longest > courses[i][0] &&
//           day + courses[i][0] - longest <= courses[i][1]) {
//         day -= longest;
//         day += courses[i][0];
//         q.pop();
//         q.push(courses[i][0]);
//         longest = q.top();
//       } else if (day + courses[i][0] <= courses[i][1]) {
//         ++ans;
//         day += courses[i][0];
//         q.push(courses[i][0]);
//         longest = q.top();
//       }
//     }
//     return ans;
//   }
// };

bool cmp(vector<int> &a, vector<int> &b) {
  if (a[1] == b[1]) return a[0] < b[0];
  return a[1] < b[1];
}
class Solution {
 public:
  int scheduleCourse(vector<vector<int>> &courses) {
    int day = 0, size = courses.size();
    priority_queue<int> q;
    if (!size) return 0;
    sort(courses.begin(), courses.end(), cmp);
    for (int i = 0; i < size; ++i) {
      q.push(courses[i][0]);
      day += courses[i][0];
      if (day > courses[i][1]) {
        day -= q.top();
        q.pop();
      }
    }
    return q.size();
  }
};