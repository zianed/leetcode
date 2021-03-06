/**
在给定的网格中，每个单元格可以有以下三个值之一：

值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。

返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。

 

示例 1：



输入：[[2,1,1],[1,1,0],[0,1,1]]
输出：4
示例 2：

输入：[[2,1,1],[0,1,1],[1,0,1]]
输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
示例 3：

输入：[[0,2]]
输出：0
解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 

提示：

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] 仅为 0、1 或 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotting-oranges
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        // 记录新鲜橘子的个数
        int countGood = 0;
        int minute = 0;
        queue<vector<int>> qPath;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    qPath.push(vector<int> {i, j});
                } else if (grid[i][j] == 1) {
                    countGood++;
                }
            }
        }
        vector<vector<int>> directions = { { -1, 0}, {0, 1}, {1, 0}, {0, -1} };
        while (!qPath.empty()) {
            minute++;
            int len = qPath.size();
            for (int i = 0; i < len; i++) {
                auto p = qPath.front();
                qPath.pop();
                // cout << minute << "=" << p[0] << "," << p[1] << endl;
                for (auto &d : directions) {
                    int i = p[0] + d[0];
                    int j = p[1] + d[1];
                    if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1) {
                        grid[i][j] = 2;
                        countGood--;
                        qPath.push(vector<int> {i, j});
                    }
                }
            }
        }
        if (countGood == 0) {
            return minute > 0 ? minute - 1 : 0;
        } else {
            return -1;
        }
    }
};

