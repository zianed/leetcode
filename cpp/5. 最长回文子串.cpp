/**
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    string longestPalindrome(string s) {
        // i->j 是回文子串，则i+1->j-1也是回文子串
        int m = s.size();
        string res;
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = i; j < m; j++) {
                if (s[i] == s[j]) {
                    if (j == i) {
                        dp[i][j] = 1;
                    } else if (j - i == 1) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    if (dp[i][j] == 1) {
                        int len = j - i + 1;
                        if (len > res.size()) {
                            res = s.substr(i, len);
                        }
                    }
                }
            }
        }
        return res;
    }
};
