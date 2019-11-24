/**
在给定的二维二进制数组 A 中，存在两座岛。（岛是由四面相连的 1 形成的一个最大组。）

现在，我们可以将 0 变为 1，以使两座岛连接起来，变成一座岛。

返回必须翻转的 0 的最小数目。（可以保证答案至少是 1。）

 

示例 1：

输入：[[0,1],[1,0]]
输出：1
示例 2：

输入：[[0,1,0],[0,0,0],[0,0,1]]
输出：2
示例 3：

输入：[[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
输出：1
 

提示：

1 <= A.length = A[0].length <= 100
A[i][j] == 0 或 A[i][j] == 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-bridge
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        // 求1到最近的1的距离
        // 最终使所有的1都在一起
        int num = 0;
        if (A.empty() || A[0].empty()) {
            return num;
        }
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> qPath;
        for (int i = 0 ;i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 1) {
                    dfs(i, j, A, qPath, visited);
                    break;
                }
            }
            if (!qPath.empty()) {
                break;
            }
        }
        while (!qPath.empty()) {
            ++num;
            int len = qPath.size();
            for (int index = 0; index < len; index++) {
                vector<int> p = qPath.front();
                qPath.pop();
                cout << num << "=" << p[0] << "," << p[1] << endl;
                for (auto &d :direction) {
                    int i = p[0] + d[0];
                    int j = p[1] + d[1];
                    if (i >=0 && i < m && j >= 0 && j < n && !visited[i][j]) {
                        if (A[i][j] == 1) {
                            return --num;
                        } else {
                            qPath.push({i, j});
                        }
                        visited[i][j] = true;
                    }
                }
            }
        }
        return --num;
    }
    
    void dfs(int i, int j, vector<vector<int>>& A, queue<vector<int>> &qPath, vector<vector<bool>> &visited)
    {
        int m = A.size();
        int n = A[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || A[i][j] == 0) {
            return;
        }
        if (visited[i][j]) {
            return;
        }
        // cout << "dfs:" << i << ", " << j << endl;
        visited[i][j] = true;
        qPath.push({i, j});
        vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (auto &d :direction) {
            dfs(i + d[0], j + d[1], A, qPath, visited);
        }
    }
};