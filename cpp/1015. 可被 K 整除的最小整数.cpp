/**
给定正整数 K，你需要找出可以被 K 整除的、仅包含数字 1 的最小正整数 N。

返回 N 的长度。如果不存在这样的 N，就返回 -1。

 

示例 1：

输入：1
输出：1
解释：最小的答案是 N = 1，其长度为 1。
示例 2：

输入：2
输出：-1
解释：不存在可被 2 整除的正整数 N 。
示例 3：

输入：3
输出：3
解释：最小的答案是 N = 111，其长度为 3。
 

提示：

1 <= K <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-integer-divisible-by-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/


/**
数学证明：
设：vaule = p * K + q
则：value * 10 + 1 = p * K * 10 + q * 10 + 1

有：value % K = q
有：(value * 10 + 1) % K = (p * K * 10 + q * 10 + 1) % K = (q * 10 + 1) % K
有：(value * 10 + 1) % K = ((value % K) * 10 + 1) % K

((value % K) * 10 + 1)可以被K整除，则(value * 10 + 1) 也可以被K整除。
将位数变小，对操作结果直接取余

**/
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) {
            return -1;
        }
        int len = 1;
        int value = 1;
        while (value % K != 0) {
            value = value % K;
            value = value * 10 + 1;
            len++;
        }
        return len;
    }
};