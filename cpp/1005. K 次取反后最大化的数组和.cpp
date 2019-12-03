/**
给定一个整数数组 A，我们只能用以下方法修改该数组：我们选择某个个索引 i 并将 A[i] 替换为 -A[i]，然后总共重复这个过程 K 次。（我们可以多次选择同一个索引 i。）

以这种方式修改数组后，返回数组可能的最大和。

 

示例 1：

输入：A = [4,2,3], K = 1
输出：5
解释：选择索引 (1,) ，然后 A 变为 [4,-2,3]。
示例 2：

输入：A = [3,-1,0,2], K = 3
输出：6
解释：选择索引 (1, 2, 2) ，然后 A 变为 [3,1,0,2]。
示例 3：

输入：A = [2,-3,-1,5,-4], K = 2
输出：13
解释：选择索引 (1, 4) ，然后 A 变为 [2,3,-1,5,4]。
 

提示：

1 <= A.length <= 10000
1 <= K <= 10000
-100 <= A[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/


class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int i = 0;
        int len = A.size();
        bool hasZero = false;
        for (; i < K && i < len - 1; i++) {
            if (A[i] < 0) {
                A[i] = - A[i];
            } else if (A[i] == 0) {
                hasZero = true;
                break;
            } else {
                break;
            }
        }
        // A[i]是大于0的
        if (!hasZero && i != K) {
            bool needChange = (K - i) % 2 == 1;
            if (needChange) {
                if (i == 0) {
                    A[i] = -A[i];
                } else {
                    // A[i - 1]是小于0的
                    if (A[i] > A[i - 1]) {
                        A[i - 1] = -A[i - 1];
                    } else {
                        A[i] = -A[i];
                    }
                }
            }
        }
        
        int sum = 0;
        for (int n : A) {
            sum += n;
        }
        return sum;
    }
};
