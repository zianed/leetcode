/**
给出一个正整数数组 nums，请你帮忙从该数组中找出能满足下面要求的 最长 前缀，并返回其长度：

从前缀中 删除一个 元素后，使得所剩下的每个数字的出现次数相同。
如果删除这个元素后没有剩余元素存在，仍可认为每个数字都具有相同的出现次数（也就是 0 次）。

 

示例 1：

输入：nums = [2,2,1,1,5,3,3,5]
输出：7
解释：对于长度为 7 的子数组 [2,2,1,1,5,3,3]，如果我们从中删去 nums[4]=5，就可以得到 [2,2,1,1,3,3]，里面每个数字都出现了两次。
示例 2：

输入：nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
输出：13
示例 3：

输入：nums = [1,1,1,2,2,2]
输出：5
示例 4：

输入：nums = [10,2,8,9,3,8,1,5,2,3,7,6]
输出：8
 

提示：

2 <= nums.length <= 10^5
1 <= nums[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-equal-frequency
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int maxValue = *max_element(nums.begin(), nums.end());
        // 每个数字出现的次数
        vector<int> counts(maxValue + 1, 0);
        int maxCount = 0;
        // 每个次数上出现的数字的个数
        int len = nums.size();
        vector<int> times(len + 1, 0);
        int res = 0;
        for (int i = 0; i < len; i++) {
            counts[nums[i]]++;
            int count = counts[nums[i]];
            maxCount = max(count, maxCount); 
            times[count]++;
            // 出现次数最多的数
            if (maxCount * times[maxCount] == i || 
                // 出现次数次多的数
                times[maxCount] == 1 && (maxCount - 1) * times[maxCount - 1] == i) {
                res = i + 1;
            }
        }
        if (maxCount == 1) {
            return len;
        }
        return res;
    }
};