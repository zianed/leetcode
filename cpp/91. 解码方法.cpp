/**
一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

示例 1:

输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
示例 2:

输入: "226"
输出: 3
解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-ways
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    int numDecodings(string s) {
        // 11~19 22~26 dp[n] = dp[n - 2] + dp[n - 1]
        // 10 20 dp[n] = dp[n - 2]
        // x0 直接返回
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            // 可以用一个数表示
            if (s[i] != '0') {
                dp[i+1] = dp[i];
            }
            if (i > 0) {
                // 可以用两个数表示
                if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                    dp[i + 1] += dp[i-1];
                }
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        // 11~19 22~26 dp[n] = dp[n - 2] + dp[n - 1]
        // 10 20 dp[n] = dp[n - 2]
        // x0 直接返回
        int n = s.size();
        vector<int> dp(n, 0);
        if (n >= 1) {
            int i = 0;
            if (s[0] != '0') {
                dp[0] = 1;
            }
        }
        if (n >= 2) {
            int i = 1;
            if (s[i] == '0' && (s[i - 1] == '1' || s[i - 1] == '2')) {
                dp[i] = 1;
            } else if (s[i] == '0') {
                dp[i] = 0;
            } else if ((s[i -1] == '1') || (s[i - 1] == '2' && s[i] <= '6')) {
                dp[i] = 2;
            } else {
                dp[i] = dp[i - 1];
            }
        }
        for (int i = 2; i < n; i++) {
            // 可以用一个数表示
            if (s[i] == '0' && (s[i - 1] == '1' || s[i - 1] == '2')) {
                dp[i] = dp[i - 2];
            } else if (s[i] == '0') {
                dp[i] = 0;
            } else if ((s[i -1] == '1') || (s[i - 1] == '2' && s[i] <= '6')) {
                dp[i] = dp[i - 2] + dp[i - 1];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};

