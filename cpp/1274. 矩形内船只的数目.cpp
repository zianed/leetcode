/**
(此题是 交互式问题 )

在用笛卡尔坐标系表示的二维海平面上，有一些船。每一艘船都在一个整数点上，且每一个整数点最多只有 1 艘船。

有一个函数 Sea.hasShips(topRight, bottomLeft) ，输入参数为右上角和左下角两个点的坐标，当且仅当这两个点所表示的矩形区域（包含边界）内至少有一艘船时，这个函数才返回 true ，否则返回 false 。

给你矩形的右上角 topRight 和左下角 bottomLeft 的坐标，请你返回此矩形内船只的数目。题目保证矩形内 至多只有 10 艘船。

调用函数 hasShips 超过400次 的提交将被判为 错误答案（Wrong Answer） 。同时，任何尝试绕过评测系统的行为都将被取消比赛资格。

 

示例：



输入：
ships = [[1,1],[2,2],[3,3],[5,5]], topRight = [4,4], bottomLeft = [0,0]
输出：3
解释：在 [0,0] 到 [4,4] 的范围内总共有 3 艘船。


 

提示：


	ships 数组只用于评测系统内部初始化。你无法得知 ships 的信息，所以只能通过调用 hasShips 接口来求解。
	0 <= bottomLeft[0] <= topRight[0] <= 1000
	0 <= bottomLeft[1] <= topRight[1] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-ships-in-a-rectangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

// 分治算法
class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        int x1 = bottomLeft[0];
        int y1 = bottomLeft[1];
        int x2 = topRight[0];
        int y2 = topRight[1];
        if (x1 > x2 || y1 > y2) {
            return 0;
        }
        if (!sea.hasShips(topRight, bottomLeft)) {
            return 0;
        }
        if (x1 == x2 && y1 == y2) {
            return 1;
        }
        // 分为四块区域，求和
        int xm = (x1 + x2) / 2;
        int ym = (y1 + y2) / 2;
        // x1, y1 ~ xm, ym
        // x1, ym + 1 ~ xm, y2
        // xm + 1, y1 ~ x2, ym
        // xm + 1, ym + 1, x1, y2
        // 左下
        return countShips(sea, {xm, ym}, {x1, y1})
            // 左上
            + countShips(sea, {xm, y2}, {x1, ym + 1})
            // 右下
            + countShips(sea, {x2, ym}, {xm + 1, y1})
            // 右上
            + countShips(sea, {x2, y2}, {xm + 1, ym + 1});
        
    }
};