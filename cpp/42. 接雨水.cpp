/**
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trapping-rain-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// 构造该点两边的数组
class Solution {
public:
    int trap(vector<int>& height) {
        int m = height.size();
        vector<int> left(m, 0);
        vector<int> right(m, 0);
        // 左边最高的值
        for (int i = 1; i < m; i++) {
            left[i] = max(left[i - 1], height[i - 1]);
        }
        // 右边最高的值
        for (int i = m - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i + 1]);
        }
        int sum = 0;
        for (int i = 1; i <= m -2; i++) {
            // 选取小的那一边
            int v = min(left[i], right[i]);
            if (v > height[i]) {
                // 矮的那一边减去当前的数值
                sum += v - height[i];
            }
        }
        return sum;
    }
};