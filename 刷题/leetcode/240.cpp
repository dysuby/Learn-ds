// class Solution {
//  public:
//   bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     int m = matrix.size();
//     if (!m) return false;
//     int n = matrix[0].size();
//     if (!n) return false;
//     int rowhead = 0, rowtail = m - 1;
//     while (matrix[rowtail / 2][0] > target && rowhead != rowtail) rowtail /= 2;
//     int colhead = 0, coltail = n - 1;
//     while (matrix[0][coltail / 2] > target && coltail != colhead) coltail /= 2;
//     for (int i = rowhead; i <= rowtail; ++i)
//       for (int j = colhead; j <= coltail; ++j)
//         if (matrix[i][j] == target) return true;
//     return false;
//   }
// };

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (!m) return false;
    int n = matrix[0].size();
    if (!n) return false;
    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
      if (matrix[i][j] < target)
        ++i;
      else if (matrix[i][j] > target)
        --j;
      else
        return true;
    }
    return false;
  }
};