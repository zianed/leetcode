/**
给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

 

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

提示：

你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。

 

进阶：

你能在线性时间复杂度内解决此题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-window-maximum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// 暴力破解
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k <= 1) {
            return nums;
        }
        vector<int> res;
        int len = nums.size();
        for (int i = k - 1; i < len; i++) {
            int v = nums[i - k + 1];
            for (int j = i - k + 2; j <= i; j++) {
                v = max(v, nums[j]);
            }
            res.push_back(v);
        }
        return res;
    }
};

// 双向队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k <= 1) {
            return nums;
        }
        vector<int> res;
        int len = nums.size();
        deque<int> qInt;
        for (int i = 0; i < len; i++) {
            // 把后面比他小的值都干掉
            while (!qInt.empty() && nums[qInt.back()] < nums[i]) {
                qInt.pop_back();
            }
            // 把前面下标超过i - k + 1的也干掉
            while (!qInt.empty() && qInt.front() < i - k + 1) {
                qInt.pop_front();
            }
            qInt.push_back(i);
            if (i >= k -1) {
                res.push_back(nums[qInt.front()]);
            }
        }
        return res;
    }
};