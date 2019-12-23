/**
给定正整数数组 A，A[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的距离为 j - i。

一对景点（i < j）组成的观光组合的得分为（A[i] + A[j] + i - j）：景点的评分之和减去它们两者之间的距离。

返回一对观光景点能取得的最高分。

 

示例：

输入：[8,1,5,2,6]
输出：11
解释：i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
 

提示：

2 <= A.length <= 50000
1 <= A[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-sightseeing-pair
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// A[i] + A[j] + i -j = (A[i] + i) + (A[j] - j)
// 要求得A[i] + i 最大的值
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A)
    {
        int result = 0;
        int maxVaule = A[0] + 0;
        int len = A.size();
        for (int i = 1; i < len; i++) {
            result = max(result, A[i] - i + maxVaule);
            maxVaule = max(maxVaule, A[i] + i);
        }
        return result;
    }
};


// 该题目的变形
// A[j] - A[i] - (j - i) = (A[j] - j) - (A[i] - i)
// 要求得A[i] -i的最小值
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A)
    {
        int result = 0;
        int minVaule = A[0] - 0;
        int len = A.size();
        for (int i = 1; i < len; i++) {
            int value = A[i] - i;
            result = max(result, value - minVaule);
            minVaule = min(minVaule, value);
        }
        return result;
    }
};
