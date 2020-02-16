/**
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// 动态规划
// dp[i][j] = dp[i + 1][j - 1] + 2;
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (i < n - 1 && j > 0) {
                    dp[i][j] = dp[i + 1][j - 1]
                }
                if (s[i] == '(' && s[j] == ')' ||
                    s[i] == '[' && s[j] == ']' ||
                    s[i] == '{' && s[j] == '}') {
                    dp[i][j] += 2;
                }
            }
        }
        return dp[0][n - 1];
    }
};

