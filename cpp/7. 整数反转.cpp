/**
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    int reverse(int x) {
        // 最小值反转后溢出
        if (x == INT_MIN) {
            return 0;
        }
        
        long num = 0;
        while (x != 0) {
            num = num * 10 + (x % 10);
            x = x / 10;
        }

        if (num > INT_MAX || num < INT_MIN) {
            return 0;
        }
        
        return num;
    }
};
