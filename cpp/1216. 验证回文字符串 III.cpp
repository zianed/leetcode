/**
给出一个字符串 s 和一个整数 k，请你帮忙判断这个字符串是不是一个「K 回文」。

所谓「K 回文」：如果可以通过从字符串中删去最多 k 个字符将其转换为回文，那么这个字符串就是一个「K 回文」。

 

示例：

输入：s = "abcdeca", k = 2
输出：true
解释：删除字符 “b” 和 “e”。


 

提示：


	1 <= s.length <= 1000
	s 中只含有小写英文字母
	1 <= k <= s.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// 求得组成回文子序列的个数
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
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
        return dp[len][len] + k >= len;
    }
};
