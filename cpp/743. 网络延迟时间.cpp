/**
有 N 个网络节点，标记为 1 到 N。

给定一个列表 times，表示信号经过有向边的传递时间。 times[i] = (u, v, w)，其中 u 是源节点，v 是目标节点， w 是一个信号从源节点传递到目标节点的时间。

现在，我们向当前的节点 K 发送了一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1。

注意:

N 的范围在 [1, 100] 之间。
K 的范围在 [1, N] 之间。
times 的长度在 [1, 6000] 之间。
所有的边 times[i] = (u, v, w) 都有 1 <= u, v <= N 且 0 <= w <= 100。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/network-delay-time
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/


// 单源非负权最短路径
// Dijistra算法
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int,int>>> graph(N + 1);
        for (auto &time : times) {
            graph[time[0]].push_back({time[1], time[2]});
        }
        
        vector<int> dis(N + 1, INT_MAX);
        dis[K] = 0;
        vector<bool> visited(N + 1, false);
        // check N - 1
        for (int index = 1; index < N; index++) {
            int start = -1;
            int value = INT_MAX;
            for (int i = 1; i <= N; i++) {
                if (!visited[i] && dis[i] < value) {
                    value = dis[i];
                    start = i;
                }
            }
            if (start == -1) {
                return -1;
            }
            visited[start] = true;
            for (auto &end: graph[start]) {
                int e = end.first;
                int v = end.second;
                if (dis[e] > dis[start] + v) {
                    dis[e] = dis[start] + v;
                }
            }
        }

        int maxV = -1;
        for (int i = 1; i <= N; i++) {
            if (dis[i] == INT_MAX) {
                return -1;
            }
            maxV = max(maxV, dis[i]);
        }
        return maxV;
    }
};

// Dijistra算法
// 使用优先队列
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int,int>>> graph(N + 1);
        for (auto &time : times) {
            graph[time[0]].push_back({time[1], time[2]});
        }
        
        vector<int> dis(N + 1, INT_MAX);
        dis[K] = 0;
        vector<bool> visited(N + 1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qPath;
        qPath.push({0, K});
        while (!qPath.empty()) {
            // 每次从堆里取最小的值
            pair<int, int> startNode = qPath.top();
            int start = startNode.second;
            qPath.pop();
            visited[start] = true;
            for (auto &end: graph[start]) {
                int e = end.first;
                int v = end.second;
                if (dis[e] > dis[start] + v) {
                    dis[e] = dis[start] + v;
                    qPath.push({dis[e], e});
                }
            }
        }

        int maxV = -1;
        for (int i = 1; i <= N; i++) {
            if (dis[i] == INT_MAX) {
                return -1;
            }
            maxV = max(maxV, dis[i]);
        }
        return maxV;
    }
};



