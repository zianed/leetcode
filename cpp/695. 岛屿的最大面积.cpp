/**
给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。

示例 2:

[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

注意: 给定的矩阵grid 的长度和宽度都不超过 50。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-area-of-island
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// 深度优先搜索
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int maxNum = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int num = dfs(i, j, m, n, grid);
                    // cout << i << "," << j << "=" << num << endl;
                    maxNum = max(maxNum, num);
                }
            }
        }
        return maxNum;
    }
    
    int dfs(int i, int j, int m, int n, vector<vector<int>>& grid)
    {
        if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1) {
            grid[i][j] = 0;
            vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
            int num = 1;
            for (auto &d :direction) {
                num += dfs(i + d[0], j + d[1], m, n, grid);
            }
            return num;
        }
        return 0;
    }
};

// 并查集求解
class DisjonintSet {
public:
    DisjonintSet(int n) : id_(n), count_(n)
    {
        for (int i = 0; i < n; i++) {
            id_[i] = i;
        }
    }
    
    void Union(int a, int b) {
        int aRoot = FindRoot(a);
        int bRoot = FindRoot(b);
        // cout << a << ":" << aRoot << "|" <<b << ":" << bRoot << endl;
        if (aRoot == bRoot) {
            return;
        } else if (aRoot < bRoot) {
            id_[bRoot] = aRoot;
            for (int i = 0; i < id_.size(); i++) {
                if (id_[i] == bRoot) {
                    id_[i] = aRoot;
                }
            }
        } else {
            id_[aRoot] = bRoot;
            for (int i = 0; i < id_.size(); i++) {
                if (id_[i] == aRoot) {
                    id_[i] = bRoot;
                }
            }
        }
        count_--;
    }
    
    void Invalid(int a)
    {
        id_[a] = -1;
        count_--;
    }
    
    int CountMax()
    {
        map<int, int> values;
        for (int i = 0; i < id_.size(); i++) {
            int a = id_[i];
            if (a == -1) {
                continue;
            }
            auto it = values.find(a);
            int count = 1;
            if (it != values.end()) {
                count = it->second + 1;
            }
            values[a] = count;
        }
        
        int count = 0;
        for (auto &it : values) {
            count = max(it.second, count);
        }
        return count;
    }
    
    void Print()
    {
        cout << id_.size() << ":[";
        for (int a : id_) {
            cout << a << ",";
        }
        cout << "]" << endl;
        cout << "count: " << count_ << endl;
    }

    int Count()
    {
        return count_;
    }
    
private:
    int FindRoot(int a)
    {
        int root = a;
        while (root != id_[root]) {
            root = id_[root];
        }
        return root;
    }
    vector<int> id_;
    int count_;
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        DisjonintSet dis(m*n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    dis.Invalid(i*n+j);
                    continue;
                }
                if (j >= 1 && grid[i][j - 1] == 1) {
                    dis.Union(i*n+j, i*n+j-1);
                }
                if (i >= 1 && grid[i - 1][j] == 1) {
                    dis.Union(i*n+j, (i - 1)*n+j);
                }
            }
        }
        dis.Print();
        return dis.CountMax();
    }
};
