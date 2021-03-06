/**
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X


运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X


解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// 深度优先
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) {
            return;
        }
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' ) {
                dfs(i, 0, m, n, board);
            }
            if (board[i][n - 1] == 'O' ) {
                dfs(i, n - 1, m, n, board);
            }
        }
        for (int j = 1; j < n - 1; j++) {
            if (board[0][j] == 'O' ) {
                dfs(0, j, m, n, board);
            }
            if (board[m - 1][j] == 'O' ) {
                dfs(m - 1, j, m, n, board);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '2') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void dfs(int i, int j, int m, int n, vector<vector<char>>& board) {
        board[i][j] = '2';
        vector<vector<int>> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
        for (auto &d : directions) {
            int ni = i + d[0];
            int nj = j + d[1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == 'O') {
                dfs(ni, nj, m, n, board);
            }
        }
    }
};

// 广度优先
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
    }
};