/**
给定一个机票的字符串二维数组 [from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些机票都属于一个从JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 出发。

说明:

如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前
所有的机场都用三个大写字母表示（机场代码）。
假定所有机票至少存在一种合理的行程。
示例 1:

输入: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
输出: ["JFK", "MUC", "LHR", "SFO", "SJC"]
示例 2:

输入: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
输出: ["JFK","ATL","JFK","SFO","ATL","SFO"]
解释: 另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"]。但是它自然排序更大更靠后。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reconstruct-itinerary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int m = tickets.size();
        map<string, vector<string>> mapFrom;
        for (auto &t : tickets) {
            mapFrom[t[0]].push_back(t[1]);
        }
        for (auto it = mapFrom.begin(); it != mapFrom.end(); it++) {
            sort(it->second.begin(), it->second.end());
        }
        vector<string> res(m + 1);
        string start = "JFK";
        dfs(start, 0, m, mapFrom, res);
        return res;
    }
    bool find = false;
    void dfs(string start, int i, int m, map<string, vector<string>> &mapFrom, vector<string> &res)
    {
        if(find) {
            return;
        }
        cout << i << "=" << start << endl;
        res[i] = start;
        if (i == m) {
            find = true;
            return;
        }
        auto it = mapFrom.find(start);
        if (it == mapFrom.end()) {
            return;
        }
        auto &des = it->second;
        int len = des.size();
        for (int index = 0; index < len; index++) {
            string city = des[index];
            if (city == "") {
                continue;
            }
            des[index] = "";
            dfs(city, i + 1, m, mapFrom, res);
            des[index] = city;
        }
    }
};
