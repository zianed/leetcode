/**
假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例

输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 身高高的排在前面
        sort(people.begin(), people.end(), [](auto &v1, auto &v2){
            return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] > v2[0];
        });
        vector<vector<int>> res;
        for (auto &p : people) {
            // 插入到对应位置，不影响已有的排序
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }
};

