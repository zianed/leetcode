/**
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

输入:
11110
11010
11000
00000

输出: 1


示例 2:

输入:
11000
11000
00100
00011

输出: 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// 深度优先搜索
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int num = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n;j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    // cout << i << "," << j << endl;
                    dfs(i, j, m, n, grid, visited);
                    num++;
                } else {
                    visited[i][j] = true;
                }
            }
        }
        return num;
    }
    void dfs(int i, int j, int m, int n, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        // cout << i << "," << j << "," << m << "," << n << endl;
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }
        if (visited[i][j]) {
            return;
        }
        if (grid[i][j] == '0') {
            return;
        }
        visited[i][j] = true;
        vector<vector<int>> direction = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (auto &d : direction) {
            dfs(i + d[0], j + d[1], m, n, grid, visited);
        }
    }
};


// 广度优先搜索
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> direction = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
        // 将找过的点都设置为0
        int num = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n;j++) {
                if (grid[i][j] == '1') {
                    num++;
                    // 从该点搜索直到搜索完所有的点
                    queue<vector<int>> qPath;
                    qPath.push({i, j});
                    grid[i][j] = '0';
                    // cout << "bfs:" << i <<"," << j << endl;
                    while (!qPath.empty()) {
                        auto p = qPath.front();
                        qPath.pop();
                        // cout << p[0] <<"," << p[1] << endl;
                        for (auto &d : direction) {
                            int ni = p[0] + d[0];
                            int nj = p[1] + d[1];
                            if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == '1') {
                                qPath.push({ni, nj});
                                grid[ni][nj] = '0';
                            }
                        }
                    }
                }
            }
        }
        return num;
    }
};


// 并查集
class DisjoinSet {
public:
    DisjoinSet(int n)
    {
        num = n;
        for (int i = 0; i < num; i++) {
            values.push_back(i);
        }
    }
    
    void Connect(int i, int j)
    {
        int ri = FindRoot(i);
        int rj = FindRoot(j);
        if (ri != rj) {
            values[ri] = rj;
            num--;
            cout << num << "=" << i << "," << j << endl;
        }
    }
    
    void Invilid(int i)
    {
        values[i] = -1;
        num--;
        cout << num << endl;
    }
    
    int FindRoot(int i)
    {
        int root = i;
        while (root != values[root]) {
            root = values[root];
        }
        return root;
    }
    int GetNum()
    {
        return num;
    }
private:
    vector<int> values;
    int num;
};


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size(); 
        DisjoinSet ds(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') {
                    ds.Invilid(i * n + j);
                } else {
                    if (i >= 1 && grid[i - 1][j] == '1') {
                        ds.Connect(i * n + j, (i - 1) * n + j);
                    }
                    if (j >= 1 && grid[i][j - 1] == '1') {
                        ds.Connect(i * n + j, i * n + j - 1);
                    }
                }
            }
        }
        return ds.GetNum();
    }
};
