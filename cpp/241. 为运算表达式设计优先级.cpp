/**
给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。

示例 1:

输入: "2-1-1"
输出: [0, 2]
解释: 
((2-1)-1) = 0 
(2-(1-1)) = 2
示例 2:

输入: "2*3-4*5"
输出: [-34, -14, -10, -10, 10]
解释: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/different-ways-to-add-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/


class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int len = input.size();
        vector<int> left;
        vector<int> right;
        for (int i = 0; i < len; i++) {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*') {
                // 计算符号左边
                left = diffWaysToCompute(input.substr(0, i));
                // 计算符号右边
                right = diffWaysToCompute(input.substr(i + 1));
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') {
                            res.push_back(l + r);
                        } else if (c == '-') {
                            res.push_back(l - r);
                        } else {
                            res.push_back(l * r);
                        }
                    }
                }
            }
        }
        // 没有符号的情况，就是个纯数字
        if (res.empty()) {
            res.push_back(stoi(input));
        }
        return res;
    }
};
