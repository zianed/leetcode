/**
给定从 0 到 n-1 标号的 n 个结点，和一个无向边列表（每条边以结点对来表示），请编写一个函数用来判断这些边是否能够形成一个合法有效的树结构。

示例 1：

输入: n = 5, 边列表 edges = [[0,1], [0,2], [0,3], [1,4]]
输出: true

示例 2:

输入: n = 5, 边列表 edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
输出: false

注意：你可以假定边列表 edges 中不会出现重复的边。由于所有的边是无向边，边 [0,1] 和边 [1,0] 是相同的，因此不会同时出现在边列表 edges 中。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/graph-valid-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// bfs搜索
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        // 把邻接表转换为临接矩阵
        for (auto &v: edges) {
            graph[v[0]][v[1]] = 1;
            graph[v[1]][v[0]] = 1;
        }
        vector<bool> visited(n, false);
        queue<int> qPath;
        qPath.push(0);
        visited[0] = true;
        while (!qPath.empty()) {
            int i = qPath.front();
            qPath.pop();
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 1) {
                    // 对向节点已经被访问过了，说明有环路出现，不能构成树
                    if (visited[j]) {
                        return false;
                    }
                    graph[i][j] = 0;
                    graph[j][i] = 0;
                    qPath.push(j);
                    visited[j] = true;
                }
            }
        }
        // 从一个点开始，所有节点都被访问过了，才能构成一棵树，否则就是多棵树
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};

// 并查集，联通的节点都放到一个集合
// 如果有两个的 父节点相同，那么他们是环路
// 如果最终的集合个数不是1，说明不是1颗树
class DisjoinSet {
    DisjoinSet(int n)
    {
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
         
    }
};

