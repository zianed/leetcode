/**
让我们一起来玩扫雷游戏！

给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。

现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：

如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的方块都应该被递归地揭露。
如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
如果在此次点击中，若无更多方块可被揭露，则返回面板。
 

示例 1：

输入: 

[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]

Click : [3,0]

输出: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

解释:

示例 2：

输入: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Click : [1,2]

输出: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'X', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

解释:

 

注意：

输入矩阵的宽和高的范围为 [1,50]。
点击的位置只能是未被挖出的方块 ('M' 或者 'E')，这也意味着面板至少包含一个可点击的方块。
输入面板不会是游戏结束的状态（即有地雷已被挖出）。
简单起见，未提及的规则在这个问题中可被忽略。例如，当游戏结束时你不需要挖出所有地雷，考虑所有你可能赢得游戏或标记方块的情况。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minesweeper
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/


// 深度优先搜索
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0];
        int c = click[1];
        
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }
        
        int m = board.size();
        int n = board[0].size();
        checkM(board, r , c, m, n);
        return board;
    }
    
    void checkM(vector<vector<char>>& board, int i, int j, int m, int n) {
        if(i <0 || i>=m || j<0 ||j>=n) {
            return;
        }
        
        if (board[i][j] != 'E') {
            return;
        }
        
        int count = 0;
        if (i-1>=0) {
            if (j-1>=0 && board[i-1][j-1] == 'M') count++;
            if (board[i-1][j] == 'M') count++;
            if (j+1<n && board[i-1][j+1] == 'M') count++;
        }
        
        if (j-1>=0 && board[i][j-1] == 'M') count++;
        if (j+1<n && board[i][j+1] == 'M') count++;
        
        if (i+1<m) {
            if (j-1>=0 && board[i+1][j-1] == 'M') count++;
            if (board[i+1][j] == 'M') count++;
            if (j+1<n && board[i+1][j+1] == 'M') count++;
        }
        
        if (count == 0) {
            board[i][j] = 'B';
            
            checkM(board, i-1 , j-1, m, n);
            checkM(board, i-1 , j, m, n);
            checkM(board, i-1 , j+1, m, n);
            checkM(board, i , j -1, m, n);
            checkM(board, i , j +1, m, n);
            checkM(board, i +1 , j -1, m, n);
            checkM(board, i +1 , j , m, n);
            checkM(board, i +1 , j +1, m, n);
        } else {
            board[i][j] = '0' + count;
            return;
        }
    }
};

// 深度优先搜索
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int i = click[0];
        int j = click[1];
        if (board[i][j] == 'M') {
            board[i][j] = 'X';
            return board;
        }
        int m = board.size();
        int n = board[0].size();
        dfs(click[0], click[1], m, n, board);
        return board;
    }
    
    void dfs(int i, int j, int m, int n, vector<vector<char>>& board)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'E') {
            return;
        }
        vector<vector<int>> direction = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};
        int num = 0;
        for (auto &d :direction) {
            int r = i + d[0];
            int c = j + d[1];
            if (r >= 0 && r < m && c >=0 && c < n && board[r][c] == 'M') {
                ++num;
            }
        }
        if (num > 0) {
            board[i][j] = '0' + num;
            return;
        }
        board[i][j] = 'B';
        for (auto &d :direction) {
            dfs(i + d[0], j + d[1], m, n, board);
        }
    }
};

// 广度优先搜索
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int i = click[0];
        int j = click[1];
        if (board[i][j] == 'M') {
            board[i][j] = 'X';
            return board;
        }
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> direction = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};
        queue<vector<int>> qPath;
        int count = getValue(i, j, m, n, board);
        if (count == 0) {
            board[i][j] = 'B';
            qPath.push({i, j});
        } else {
            board[i][j] = '0' + count;
        }
        while (!qPath.empty()) {
            vector<int> p = qPath.front();
            qPath.pop();
            int r = p[0];
            int c = p[1];
            for (auto &d : direction) {
                int k = r + d[0];
                int l = c + d[1];
                if (k >= 0 && k < m && l >= 0 && l < n && board[k][l] == 'E') {
                    int num = getValue(k, l, m, n, board);
                    cout << k << "," << l << " = " << num << endl;
                    if (num == 0) {
                        board[k][l] = 'B';
                        qPath.push({k, l});
                    } else {
                        board[k][l] = '0' + num;
                    }
                }
            }
        }
        return board;
    }
    
    int getValue(int i, int j, int m, int n, vector<vector<char>>& board)
    {
        int num = 0;
        if (i >= 1 && j >= 1 && board[i - 1][j - 1] == 'M') {
            num++;
        }
        if (i >= 1 && board[i - 1][j] == 'M') {
            num++;
        }
        if (i >= 1 && j < n - 1 && board[i - 1][j + 1] == 'M') {
            num++;
        }
        if (j >= 1 && board[i][j - 1] == 'M') {
            num++;
        }
        if (j < n - 1 && board[i][j + 1] == 'M') {
            num++;
        }
        if (i < m - 1 && j >= 1 && board[i + 1][j - 1] == 'M') {
            num++;
        }
        if (i < m - 1 && board[i + 1][j] == 'M') {
            num++;
        }
        if (i < m - 1 && j < n - 1 && board[i + 1][j + 1] == 'M') {
            num++;
        }
        return num;
    }
};
