/**
给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

示例 1:
输入:

0 0 0
0 1 0
0 0 0
输出:

0 0 0
0 1 0
0 0 0
示例 2:
输入:

0 0 0
0 1 0
1 1 1
输出:

0 0 0
0 1 0
1 2 1
注意:

给定矩阵的元素个数不超过 10000。
给定矩阵中至少有一个元素是 0。
矩阵中的元素只在四个方向上相邻: 上、下、左、右。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/01-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return matrix;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        // 首先找到所有与0相接的1，然后开始按层次来搜索
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> qPath;
        for (int i = 0; i < m; i++) {
            for (int j = 0 ; j < n; j++) {
                if (matrix[i][j] == 1) {
                    for (auto &d : direction) {
                        int r = i + d[0];
                        int c = j + d[1];
                        if (r >= 0 && r < m && c >= 0 && c < n && matrix[r][c] == 0) {
                            qPath.push({i, j});
                            visited[i][j] = true;
                            continue;
                        }
                    }
                }
            }
        }
        int dis = 1;
        while (!qPath.empty()) {
            dis++;
            int len = qPath.size();
            for (int i = 0; i < len; i++) {
                vector<int> p = qPath.front();
                qPath.pop();
                for (auto &d : direction) {
                    int r = p[0] + d[0];
                    int c = p[1] + d[1];
                    if (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c] && matrix[r][c] == 1) {
                        matrix[r][c] = dis;
                        qPath.push({r, c});
                        visited[r][c] = true;
                    }
                }
            }
        }
        return matrix;
    }
};
