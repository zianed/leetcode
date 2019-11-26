/**
给定一个字符串数组 arr，字符串 s 是将 arr 某一子序列字符串连接所得的字符串，如果 s 中的每一个字符都只出现过一次，那么它就是一个可行解。

请返回所有可行解 s 中最长长度。

 

示例 1：

输入：arr = ["un","iq","ue"]
输出：4
解释：所有可能的串联组合是 "","un","iq","ue","uniq" 和 "ique"，最大长度为 4。
示例 2：

输入：arr = ["cha","r","act","ers"]
输出：6
解释：可能的解答有 "chaers" 和 "acters"。
示例 3：

输入：arr = ["abcdefghijklmnopqrstuvwxyz"]
输出：26
 

提示：

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] 中只含有小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// 暴力破解
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<set<char>> vec;
        int maxLen = 0;
        for (auto &s : arr) {
            // 如果s中有重复字符串则不添加
            vector<int> nums(26, 0);
            bool canUse = true;
            for (char c: s) {
                nums[c - 'a']++;
                if (nums[c - 'a'] > 1) {
                    canUse = false;
                    break;
                }
            }
            if (!canUse) {
                continue;
            }
            int size = vec.size();
            for (int i = 0; i < size; i++) {
                auto &setChar = vec[i];
                // cout << ":";
                // for (char c : setChar) {
                //     cout << c << ",";
                // }
                // cout << endl;
                bool find = false;
                for (char c: s) {
                    if (setChar.find(c) != setChar.end()) {
                        find = true;
                        break;
                    }
                }
                if (!find) {
                    set<char> sChar(s.begin(), s.end());
                    sChar.insert(setChar.begin(), setChar.end());
                    int len = sChar.size();
                    maxLen = max(maxLen, len);
                    vec.push_back(sChar);
                }
            }
            set<char> sChar(s.begin(), s.end());
            int len = sChar.size();
            maxLen = max(maxLen, len);
            vec.push_back(sChar);
        }
        return maxLen;
    }
};
