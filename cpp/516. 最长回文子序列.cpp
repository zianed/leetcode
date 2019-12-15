/**
给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。

示例 1:
输入:

"bbbab"
输出:

4
一个可能的最长回文子序列为 "bbbb"。

示例 2:
输入:

"cbbd"
输出:

2
一个可能的最长回文子序列为 "bb"。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= len; j++) {
                if (s[i - 1] == s[len - j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[len][len];
    }
};


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();        
        vector<vector<int>> dp;
        vector<int> vec(len, 0);
        for (int i = 0; i<len; i++) {
            dp.push_back(vec);
        }
        
        // s[i] == s[j] : f(i, j) = f(i+1, j-1) +2
        // s[i] != s[j] : f(i, j) = max(f(i+1, j), f(i, j-1))
        // i dec, use +1
        // j inc, use -1
        for (int i = len -1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < len; j++) {
                if(s.at(i) == s.at(j)) {
                    dp[i][j] = dp[i + 1][j - 1]  + 2;
                }
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[0][len -1];
    }
};

