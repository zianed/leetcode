/**
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// 回溯算法
class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        backtrack(0, 0, n, "", res);
        return res;
    }
    
    void backtrack(int l, int r, int n, string s, vector<string> &res)
    {
        if (l > n || r > n || r > l) {
            return;
        }
        if (l == n && r == n) {
            res.push_back(s);
            return;
        }
        backtrack(l + 1, r, n, s + "(", res);
        backtrack(l, r + 1, n, s + ")", res);
    }
};

