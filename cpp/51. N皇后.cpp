/**
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。



上图为 8 皇后问题的一种解法。

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例:

输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-queens
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// 回溯算法
class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> vec(n, string(n, '.'));
        backtrack(0, n, vec, res);
        return res;
    }

    void backtrack(int i, int n, vector<string> &vec, vector<vector<string>> &res)
    {
        if (i == n) {
            res.push_back(vec);
            return;
        }
        for (int j = 0; j < n; j++) {
            vec[i][j] = 'Q';
            // 当前加入的Q有效之后再递归下一次
            if (valid(i, j, n, vec)) {
                backtrack(i + 1, n, vec, res);
            }
            vec[i][j] = '.';
        }
    }
    bool valid(int r, int c, int n, vector<string> &vec)
    {
        // row
        for (int j = c - 1; j >= 0; j--) {
            if (vec[r][j] == 'Q') {
                return false;
            }
        }
        // col
        for (int i = r - 1; i >= 0; i--) {
            if (vec[i][c] == 'Q') {
                return false;
            }
        }
        // anti-digonal
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (vec[i][j] == 'Q') {
                return false;
            }
        }
        // digonal
        for (int i = r -1, j = c + 1; i >= 0 && j < n; i--, j++) {
            if (vec[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};

