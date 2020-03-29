/**
给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

示例:

输入: 
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

输出: ["eat","oath"]
说明:
你可以假设所有输入都由小写字母 a-z 组成。

提示:

你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？ 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/


class TrieNode {
public:
    TrieNode()
    {
    }

    ~TrieNode()
    {
        for (int i = 0; i < children.size(); i++) {
            if (children[i] != nullptr) {
                delete children[i];
            }
        }
    }

    string s;
    vector<TrieNode*> children{26};
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // tire tree
        TrieNode *root = new TrieNode();
        for (string &word : words) {
            TrieNode* parent = root;
            for (int i = 0; i < word.size(); i++) {
                int index = word[i] - 'a';
                if (parent->children[index] == nullptr) {
                    TrieNode* node = new TrieNode();
                }
                parent = parent->children[index];
            }
            parent->s = word;
            // cout << "[" << word << "]" << endl;
        }
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<string> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << ":" << i << "," << j << "=" << board[i][j] << endl;
                backtrack(i, j, m, n, board, visited, res, root);
            }
        }
        return res;
    }
    
    void backtrack(int i, int j, int m, int n, vector<vector<char>>& board, vector<vector<bool>> &visited, vector<string> &res, TrieNode *node) {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || node == nullptr) {
            return;
        }
        cout << "-" << i << "," << j << "=" << board[i][j] << endl;
        int index = board[i][j] - 'a';
        if (node->children[index] == nullptr) {
            return;
        }
        TrieNode *nextNode = node->children[index];
        if (nextNode == nullptr) {
            return;
        }
        cout << "-" << i << "," << j << "==" << nextNode->s << endl;
        if (!nextNode->s.empty()) {
            auto it = find(res.begin(), res.end(), nextNode->s);
            if (it == res.end()) {
                res.push_back(nextNode->s);
            }
            return;
        }
        visited[i][j] = true;
        backtrack(i + 1, j, m, n, board, visited, res, nextNode);
        backtrack(i - 1, j, m, n, board, visited, res, nextNode);
        backtrack(i, j + 1, m, n, board, visited, res, nextNode);
        backtrack(i, j - 1, m, n, board, visited, res, nextNode);
        visited[i][j] = false;
    }
};
