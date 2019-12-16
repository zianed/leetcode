/**
有 k 种颜色的涂料和一个包含 n 个栅栏柱的栅栏，每个栅栏柱可以用其中一种颜色进行上色。

你需要给所有栅栏柱上色，并且保证其中相邻的栅栏柱 最多连续两个 颜色相同。然后，返回所有有效涂色的方案数。

注意:
n 和 k 均为非负的整数。

示例:

输入: n = 3，k = 2
输出: 6
解析: 用 c1 表示颜色 1，c2 表示颜色 2，所有可能的涂色方案有:

            柱 1    柱 2   柱 3     
 -----      -----  -----  -----       
   1         c1     c1     c2 
   2         c1     c2     c1 
   3         c1     c2     c2 
   4         c2     c1     c1  
   5         c2     c1     c2
   6         c2     c2     c1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/paint-fence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    int numWays(int n, int k) {
        if (n * k == 0) {
            return 0;
        }
        if (n == 1) {
            return k;
        }
        int diff = k * (k -1);
        int same = k;
        for (int i = 2; i < n; i++) {
            int temp = diff;
            // 如果前两个栅栏的颜色相同，当前栅栏有 (k - 1) 种涂色方式
            diff = (diff + same) * (k - 1);
            // 如果前两个栅栏的颜色不同，当前栅栏有 (k) 种涂色方式
            same = temp;
        }
        return diff + same;
    }
};
