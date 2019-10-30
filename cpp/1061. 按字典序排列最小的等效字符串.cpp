/**
1061. 按字典序排列最小的等效字符串
给出长度相同的两个字符串：A 和 B，其中 A[i] 和 B[i] 是一组等价字符。举个例子，如果 A = "abc" 且 B = "cde"，那么就有 'a' == 'c', 'b' == 'd', 'c' == 'e'。

等价字符遵循任何等价关系的一般规则：

自反性：'a' == 'a'
对称性：'a' == 'b' 则必定有 'b' == 'a'
传递性：'a' == 'b' 且 'b' == 'c' 就表明 'a' == 'c'
例如，A 和 B 的等价信息和之前的例子一样，那么 S = "eed", "acd" 或 "aab"，这三个字符串都是等价的，而 "aab" 是 S 的按字典序最小的等价字符串

利用 A 和 B 的等价信息，找出并返回 S 的按字典序排列最小的等价字符串。

 

示例 1：

输入：A = "parker", B = "morris", S = "parser"
输出："makkek"
解释：根据 A 和 B 中的等价信息，我们可以将这些字符分为 [m,p], [a,o], [k,r,s], [e,i] 共 4 组。每组中的字符都是等价的，并按字典序排列。所以答案是 "makkek"。
示例 2：

输入：A = "hello", B = "world", S = "hold"
输出："hdld"
解释：根据 A 和 B 中的等价信息，我们可以将这些字符分为 [h,w], [d,e,o], [l,r] 共 3 组。所以只有 S 中的第二个字符 'o' 变成 'd'，最后答案为 "hdld"。
示例 3：

输入：A = "leetcode", B = "programs", S = "sourcecode"
输出："aauaaaaada"
解释：我们可以把 A 和 B 中的等价字符分为 [a,o,e,r,s,c], [l,p], [g,t] 和 [d,m] 共 4 组，因此 S 中除了 'u' 和 'd' 之外的所有字母都转化成了 'a'，最后答案为 "aauaaaaada"。
 

提示：

字符串 A，B 和 S 仅有从 'a' 到 'z' 的小写英文字母组成。
字符串 A，B 和 S 的长度在 1 到 1000 之间。
字符串 A 和 B 长度相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lexicographically-smallest-equivalent-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        map<char, char> cMap;
        int len = A.size();
        for (int i = 0; i < len; i++) {
            auto itA = cMap.find(A[i]);
            char vA = A[i];
            if (itA != cMap.end()) {
                vA = itA->second;
            }
            
            auto itB = cMap.find(B[i]);
            char vB = B[i];
            if (itB != cMap.end()) {
                vB = itB->second;
            }
            // 找到最小值
            char low = min(vA, min(vB, min(A[i], B[i])));
            for (auto it = cMap.begin(); it != cMap.end(); it++) {
                // 如果是其中一个都设置为最小值
                if (it->second == vA || it->second == vB || it->second == A[i] || it->second == B[i]) {
                    it->second = low;
                }
            }
            cMap[vA] = low;
            cMap[vB] = low;
        }
        
        int sSize = S.size();
        for (int i = 0; i < sSize; i++) {
            if (cMap.find(S[i]) != cMap.end()) {
                S[i] = cMap[S[i]];
            }
        }
        return S;
    }
};
