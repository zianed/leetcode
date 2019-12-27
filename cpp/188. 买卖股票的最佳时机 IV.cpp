/**
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [2,4,1], k = 2
输出: 2
解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2:

输入: [3,2,6,5,0,3], k = 2
输出: 7
解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/


// 动态规划
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        for (int j = 1; j <= k; j++) {
            int minV = prices[0];
            for (int i = 1; i < n; i++) {
                minV = min(minV, prices[i] - dp[i - 1][j - 1]);
                // 最大值
                dp[i][j] = max(dp[i - 1][j], prices[i] - minV);
                cout << i << "," << j << "=" << dp[i][j] << endl;
            }
        }
        return dp[n - 1][k];
    }
};
