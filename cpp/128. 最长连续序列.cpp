/**
给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int maxSum = 1;
        int start = nums[0];
        int len = nums.size();
        int sum = 1;
        for (int i = 1; i < len; i++) {
            // 有连续数字的时候，跳过
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            // 连续的时候，数量加1
            if (nums[i] == start + 1) {
                sum++;
            } else {
                sum = 1;
            }
            start = nums[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 构造一个set
        unordered_set<int> tmp(nums.begin(), nums.end());
        int maxSum = 0;
        for (int n : nums) {
            if (tmp.erase(n)) {
                int sum = 1;
                // 删除前面的
                int pre = n;
                while (tmp.erase(--pre)) {
                    sum++;
                }
                // 删除后面的
                int post = n;
                while (tmp.erase(++post)) {
                    sum++;
                }
                maxSum = max(sum, maxSum);
            }
        }
        return maxSum;
    }
};
