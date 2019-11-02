/**
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// 最标准的动态规划
// dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + dp[i][j]
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 第一行
                if (i == 0 && j > 0) {
                    grid[i][j] = grid[i][j - 1] + grid[i][j];
                }
                // 第一列
                if (j == 0 && i > 0) {
                    grid[i][j] = grid[i - 1][j] + grid[i][j];
                }
                if (i > 0 && j > 0) {
                    grid[i][j] = min(grid[i][j - 1], grid[i - 1][j]) + grid[i][j];
                }
            }
        }
        return grid[m - 1][n - 1];
    }
};
