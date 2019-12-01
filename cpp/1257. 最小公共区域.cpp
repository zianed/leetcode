/**
给你一些区域列表 regions ，每个列表的第一个区域都包含这个列表内所有其他区域。

很自然地，如果区域 X 包含区域 Y ，那么区域 X  比区域 Y 大。

给定两个区域 region1 和 region2 ，找到同时包含这两个区域的 最小 区域。

如果区域列表中 r1 包含 r2 和 r3 ，那么数据保证 r2 不会包含 r3 。

数据同样保证最小公共区域一定存在。

 

示例 1：

输入：
regions = [["Earth","North America","South America"],
["North America","United States","Canada"],
["United States","New York","Boston"],
["Canada","Ontario","Quebec"],
["South America","Brazil"]],
region1 = "Quebec",
region2 = "New York"
输出："North America"


 

提示：


	2 <= regions.length <= 10^4
	region1 != region2
	所有字符串只包含英文字母和空格，且最多只有 20 个字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-common-region
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        // 构造父节点map和高度
        map<string, string> father;
        map<string, int> height;
        for (auto &vec : regions) {
            int len = vec.size();
            for (int i = 1; i < len; i++) {
                father[vec[i]] = vec[0];
                if (height.find(vec[0]) == height.end()) {
                    height[vec[0]] = 0;
                }
                height[vec[i]] = height[vec[0]] + 1;
            }
        }
        while (father[region1] != region2 && father[region2] != region1 && father[region1] != father[region2]) {
            if (height[region1] > height[region2]) {
                region1 = father[region1];
            } else if (height[region1] < height[region2]) {
                region2 = father[region2];
            } else {
                region1 = father[region1];
                region2 = father[region2];
            }
        }
        if (father[region1] == region2) {
            return region2;
        } else if (father[region2] == region1) {
            return region1;
        } else {
            return father[region1];
        }
    }
};
