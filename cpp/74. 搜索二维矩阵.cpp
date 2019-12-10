/**
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
示例 1:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true
示例 2:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-a-2d-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        // 二分法查找 0 -> m * n - 1
        int l = 0;
        int n = matrix[0].size();
        int r = matrix.size() * n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            int i = m / n;
            int j = m % n;
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return false;
    }
};
