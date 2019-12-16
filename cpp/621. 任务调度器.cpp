/**
给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26 种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。

然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。

你需要计算完成所有任务所需要的最短时间。

示例 1：

输入: tasks = ["A","A","A","B","B","B"], n = 2
输出: 8
执行顺序: A -> B -> (待命) -> A -> B -> (待命) -> A -> B.


注：


	任务的总个数为 [1, 10000]。
	n 的取值范围为 [0, 100]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/task-scheduler
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        if (tasks.empty()) {
            return 0;
        }
        map<char, int> taskMap;
        for (char t : tasks) {
            if (taskMap.find(t) == taskMap.end()) {
                taskMap[t] = 1;
            } else {
                taskMap[t] = taskMap[t] + 1;
            }
        }
        vector<pair<char, int>> taskPair;
        for (auto it = taskMap.begin(); it != taskMap.end(); it++) {
            taskPair.push_back(pair<char, int>(it->first, it->second));
        }
        sort(taskPair.begin(), taskPair.end(), [](auto &p1, auto p2){
            return p1.second > p2.second; 
        });

        int num = 0;
        auto &p = taskPair[0];
        num = (p.second - 1) * (n + 1) + 1;
        
        for (int i = 1; i < taskPair.size(); i++) {
            auto &pi = taskPair[i];
            if (pi.second == p.second) {
                num++;
            } else {
                break;
            }
        }
        return num < tasks.size() ? tasks.size() : num;
    }
};