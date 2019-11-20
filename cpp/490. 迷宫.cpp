/**
由空地和墙组成的迷宫中有一个球。球可以向上下左右四个方向滚动，但在遇到墙壁前不会停止滚动。当球停下时，可以选择下一个方向。

给定球的起始位置，目的地和迷宫，判断球能否在目的地停下。

迷宫由一个0和1的二维数组表示。 1表示墙壁，0表示空地。你可以假定迷宫的边缘都是墙壁。起始位置和目的地的坐标通过行号和列号给出。

 

示例 1:

输入 1: 迷宫由以下二维数组表示

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

输入 2: 起始位置坐标 (rowStart, colStart) = (0, 4)
输入 3: 目的地坐标 (rowDest, colDest) = (4, 4)

输出: true

解析: 一个可能的路径是 : 左 -> 下 -> 左 -> 下 -> 右 -> 下 -> 右。



示例 2:

输入 1: 迷宫由以下二维数组表示

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

输入 2: 起始位置坐标 (rowStart, colStart) = (0, 4)
输入 3: 目的地坐标 (rowDest, colDest) = (3, 2)

输出: false

解析: 没有能够使球停在目的地的路径。



 

注意:


	迷宫中只有一个球和一个目的地。
	球和目的地都在空地上，且初始时它们不在同一位置。
	给定的迷宫不包括边界 (如图中的红色矩形), 但你可以假设迷宫的边缘都是墙壁。
	迷宫至少包括2块空地，行数和列数均不超过100。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-maze
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// 广度优先搜索
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze.empty() || maze[0].empty()) {
            return false;
        }
        int m = maze.size();
        int n = maze[0].size();
        // 记忆，对于访问过的点不再访问
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<vector<int>> qPath;
        qPath.push(start);
        while (!qPath.empty()) {
            auto q = qPath.front();
            qPath.pop();
            if (q[0] == destination[0] && q[1] == destination[1]) {
                return true;
            }
            visited[q[0]][q[1]] = true;
            for (auto &d : directions) {
                int i = q[0] + d[0];
                int j = q[1] + d[1];
                while (i >= 0 && i < m && j >=0 && j < n && maze[i][j] == 0) {
                    i += d[0];
                    j += d[1];
                }
                i -= d[0];
                j -= d[1];
                if (!visited[q[0]][q[1]]) {
                    qPath.push(vector<int> {i, j});
                }
            }
        }
        return false;
    }
};

// 深度优先搜索
