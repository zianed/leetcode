/**
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
示例 2:

输入: coins = [2], amount = 3
输出: -1
说明:
你可以认为每种硬币的数量是无限的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-change
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// dp[i] = min(dp[i], dp[i -c] + 1)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        // 0个硬币组成0
        dp[0] = 0;
        for (int c : coins) {
            for (int i = 1; i <= amount; i++) {
                if (i - c >= 0 && dp[i - c] != INT_MAX) {
                    // 选取该硬币的条件是选取该硬币后，数值变小了
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX) {
            return -1;
        } else {
            return dp[amount];
        }
    }
};

// 另外一种问法是有多少种组合？
// dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]]
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty() || amount < 0) {
            return 0;
        }
        int len = coins.size();
        vector<vector<int>> dp(m, vector<int>(amount + 1, 0));
        // 不用任何硬币可以组成0
        for (int i = 0; i < len; i++) {
            dp[i][0] = 1;
        }
        // coins[0] 可以组成的是他的倍数
        for (int j = 1; coins[0] * j <= amount; j++) {
            dp[0][coins[0] * j] = 1;
        }
        for (int i = 1; i < len; i++) {
            for (int i = j; j <= amount; j++) {
                // 不使用当前硬币
                dp[i][j] = dp[i - 1][j];
                if (j - coins[i] >= 0) {
                    // 使用当前硬币
                    dp[i][j] += dp[i][j - coins[i]];
                }
            }
        }
        return dp[len - 1][amount];
    }
};
