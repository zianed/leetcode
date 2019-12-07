/**
现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？

示例 1:

输入: 2, [[1,0]] 
输出: true
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
示例 2:

输入: 2, [[1,0],[0,1]]
输出: false
解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
说明:

输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
你可以假定输入的先决条件中没有重复的边。
提示:

这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
拓扑排序也可以通过 BFS 完成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/course-schedule
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// 拓扑排序算法
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (auto &p :prerequisites) {
            in[p[0]]++;
            graph[p[1]].push_back(p[0]);
        }
        // 入度为0的点作为起点
        queue<int> qPath;
        for (int i = 0; i < numCourses; i++) {
            if(in[i] == 0) {
                qPath.push(i);
            }
        }
        while (!qPath.empty()) {
            int p = qPath.front();
            qPath.pop();
            // 与其连接的所有点的入度减1
            for (int d : graph[p]) {
                in[d]--;
                if (in[d] == 0) {
                    qPath.push(d);
                }
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (in[i] != 0) {
                return false;
            }
        }
        return true;
    }
};


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degree(numCourses, 0);
        map<int, vector<int>> mPath;
        for (auto &p : prerequisites) {
            degree[p[0]]++;
            mPath[p[1]].push_back(p[0]);
        }
        vector<bool> visited(numCourses, false);
        vector<int> res;
        // 最多处理定点次
        for (int i = 0; i < numCourses; i++) {
            // 每次找到一个入度为0的点
            int v = -1;
            for (int index = 0; index < numCourses; index++) {
                if (!visited[index] && degree[index] == 0) {
                    v = index;
                    break;
                }
            }
            if (v == -1) {
                return false;
            }
            res.push_back(v);
            visited[v] = true;
            for (int j : mPath[v]) {
                degree[j]--;
            }
        }
        return true;
    }
};