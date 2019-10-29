/**
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        deque<char> charDeque;
        int maxLen = 0;
        for (char c: s) {
            auto it = find(charDeque.begin(), charDeque.end(), c);
            if (it != charDeque.end()) {
                // 统计不重复字符的个数
                int len = charDeque.size();
                maxLen = max(maxLen, len);
                // 擦除该字符前的所有字符
                charDeque.erase(charDeque.begin(), ++it);
            }
            // 依次插入每一个字符
            charDeque.push_back(c);
        }
        // 统计不重复字符的个数
        int len = charDeque.size();
        maxLen = max(maxLen, len);
        return maxLen;
    }
};