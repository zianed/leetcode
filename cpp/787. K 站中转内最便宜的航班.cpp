/**
有 n 个城市通过 m 个航班连接。每个航班都从城市 u 开始，以价格 w 抵达 v。

现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到从 src 到 dst 最多经过 k 站中转的最便宜的价格。 如果没有这样的路线，则输出 -1。

示例 1:
输入: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
输出: 200
解释: 
城市航班图如下


从城市 0 到城市 2 在 1 站中转以内的最便宜价格是 200，如图中红色所示。
示例 2:
输入: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
输出: 500
解释: 
城市航班图如下


从城市 0 到城市 2 在 0 站中转以内的最便宜价格是 500，如图中蓝色所示。
提示：

n 范围是 [1, 100]，城市标签从 0 到 n - 1.
航班数量范围是 [0, n * (n - 1) / 2].
每个航班的格式 (src, dst, price).
每个航班的价格范围是 [1, 10000].
k 范围是 [0, n - 1].
航班没有重复，且不存在环路

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cheapest-flights-within-k-stops
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// 动态规划
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> dp(n, vector<int>(K + 2, INT_MAX));
        for(int k = 0; k <= K + 1; ++k) {
            dp[src][k] = 0;
        }
        for(int k = 1; k <= K + 1; ++k) {
            for(auto &flight : flights) {
                int start = flight[0];
                int finish = flight[1];
                if (dp[start][k - 1] != INT_MAX) {
                    dp[finish][k] = min(dp[finish][k], dp[start][k-1] + flight[2]);
                }
            }
        }
        return dp[dst][K + 1] == INT_MAX ? -1 : dp[dst][K + 1];
    }
};

// Bellman-Ford运行K轮
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> cheapest_cost(n, INT_MAX);
        cheapest_cost[src] = 0;
        for (int i = 0; i <= K; ++i) {
            vector<int> new_cheapest_cost(cheapest_cost);
            for (auto& flight : flights) {
                if (cheapest_cost[flight[0]] != INT_MAX) {
                    new_cheapest_cost[flight[1]] = min(new_cheapest_cost[flight[1]], cheapest_cost[flight[0]] + flight[2]);
                }
            }
            cheapest_cost = new_cheapest_cost;
        }
        return cheapest_cost[dst] == INT_MAX ? -1 : cheapest_cost[dst];
    }
};

// 广度搜索
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        int minCost = INT_MAX;
        // 有向图
        vector<vector<int>> graph(n, vector<int>(n, -1));
        for (auto &f : flights) {
            graph[f[0]][f[1]] = f[2];
        }
        vector<bool> visited(n, false);
        visited[src] = true;
        dfs(graph, visited, n, dst, K, 0, src, 0, minCost);
        return minCost == INT_MAX ? -1 : minCost;
    }

    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int n, int dst, int K, int haveCost, int src, int myK, int &minCost)
    {
        if (src == dst) {
            minCost = min(minCost, haveCost);
            return;
        }
        if (myK > K || haveCost >= minCost){
            return;
        }
        for (int i = 0; i < n; ++i){
            if (!visited[i] && graph[src][i] != -1){
                visited[i] = true;
                dfs(graph, visited, n, dst, K, haveCost + graph[src][i], i, myK + 1, minCost);
                visited[i] = false;
            }
        }
    }
};
