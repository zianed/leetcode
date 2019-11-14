/**
给定两个整数 A 和 B，返回任意字符串 S，要求满足：

S 的长度为 A + B，且正好包含 A 个 'a' 字母与 B 个 'b' 字母；
子串 'aaa' 没有出现在 S 中；
子串 'bbb' 没有出现在 S 中。
 

示例 1：

输入：A = 1, B = 2
输出："abb"
解释："abb", "bab" 和 "bba" 都是正确答案。
示例 2：

输入：A = 4, B = 1
输出："aabaa"
 

提示：

0 <= A <= 100
0 <= B <= 100
对于给定的 A 和 B，保证存在满足要求的 S。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-without-aaa-or-bbb
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// A > B的时候就放两个A再放B
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string s;
        int numA = A;
        int numB = B;
        char a = 'a';
        char b = 'b';
        if (numA < numB) {
            swap(numA, numB);
            swap(a, b);
        }
        
        while (numA > 0 || numB > 0) {
            if (numA > 0 {
                s.append(1, a);
                numA--;
            }
            if (numA > numB) {
                s.append(1, a);
                numA--;
            }
            if (numB > 0) {
                s.append(1, b);
                numB--;
            }        }
        return s;
    }
};
