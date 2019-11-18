/**
你被给定一个 m × n 的二维网格，网格中有以下三种可能的初始化值：


	-1 表示墙或是障碍物
	0 表示一扇门
	INF 无限表示一个空的房间。然后，我们用 231 - 1 = 2147483647 代表 INF。你可以认为通往门的距离总是小于 2147483647 的。


你要给每个空房间位上填上该房间到 最近 门的距离，如果无法到达门，则填 INF 即可。

示例：

给定二维网格：

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF


运行完你的函数后，该网格应该变成：

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/walls-and-gates
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size() == 0 || rooms[0].size() == 0) {
            return;
        }
        int inf = 2147483647;
        int m = rooms.size();
        int n = rooms[0].size();
        // 找出所有的门，从门开始计算，每一圈对空房间加1
        queue<pair<int, int>> qPath;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    qPath.push(make_pair(i, j));
                }
            }
        }
        int dis =0;
        vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
        while (!qPath.empty()) {
            dis++;
            int len = qPath.size();
            for (int i = 0; i < len; i++) {
                auto q = qPath.front();
                qPath.pop();
                for (auto &d : directions) {
                    int i = q.first + d[0];
                    int j = q.second + d[1];
                    if (i >= 0 && i < m && j >= 0 && j < n && rooms[i][j] == inf) {
                        rooms[i][j] = dis;
                        qPath.push(make_pair(i, j));
                    }
                }
            }
        }
    }
};

