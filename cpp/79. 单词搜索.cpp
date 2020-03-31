/**
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false
 

提示：

board 和 word 中只包含大写和小写英文字母。
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                backtrack(i, j, m, n, board, visited, word, 0);
                if (findFlag) {
                    return true;
                }
            }
        }
        return false;
    }
    void backtrack(int i, int j, int m, int n, vector<vector<char>>& board, vector<vector<bool>> &visited, string &word, int index) {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || findFlag) {
            return;
        }
        if (board[i][j] != word[index]) {
            return;
        }
        if (index == word.size() - 1) {
            return true;
        }
        // cout << "[]" << i << "," << j << "=" << board[i][j] << "," << index << endl;
        visited[i][j] = true;
        backtrack(i + 1, j, m, n, board, visited, word, index + 1);
        backtrack(i - 1, j, m, n, board, visited, word, index + 1);
        backtrack(i, j + 1, m, n, board, visited, word, index + 1);
        backtrack(i, j - 1, m, n, board, visited, word, index + 1);
        visited[i][j] = false;
    }
    bool findFlag {false};
};

// 超时算法
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                string w;
                backtrack(i, j, m, n, board, visited, word, w);
                if (findFlag) {
                    return true;
                }
            }
        }
        return false;
    }
    void backtrack(int i, int j, int m, int n, vector<vector<char>>& board, vector<vector<bool>> &visited, string &word, string w) {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || findFlag) {
            return;
        }
        w.append(1, board[i][j]);
        // cout << "[+]" << i << "," << j << "=" << w << endl;
        if (word == w) {
            findFlag = true;
            return;
        }
        if (word.substr(0, w.size()) != w) {
            return;
        }
        // cout << "[-]" << i << "," << j << "=" << w << endl;
        visited[i][j] = true;
        backtrack(i + 1, j, m, n, board, visited, word, w);
        backtrack(i - 1, j, m, n, board, visited, word, w);
        backtrack(i, j + 1, m, n, board, visited, word, w);
        backtrack(i, j - 1, m, n, board, visited, word, w);
        visited[i][j] = false;
    }
    bool findFlag {false};
};
