/**
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
 

示例2:

输入: s1= "ab" s2 = "eidboaoo"
输出: False
 

注意：

输入的字符串只包含小写字母
两个字符串的长度都在 [1, 10,000] 之间

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// 滑窗处理
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 > len2) {
            return false;
        }
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);
        for (int i = 0; i < len1; i++) {
            hash1[s1[i] - 'a']++;
            hash2[s2[i] - 'a']++;
        }
        if (hash1 == hash2) {
            return true;
        }
        for (int i = len1; i < len2; i++) {
            // 已经过去的位置
            hash2[s2[i - len1] - 'a']--;
            // 当前位置
            hash2[s2[i] - 'a']++;
            if (hash1 == hash2) {
                return true;
            }
        }
        return false;
    }
};


// 另外一种问法，返回对应的位置
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 > len2) {
            return -1;
        }
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);
        for (int i = 0; i < len1; i++) {
            hash1[s1[i] - 'a']++;
            hash2[s2[i] - 'a']++;
        }
        if (hash1 == hash2) {
            return 0;
        }
        for (int i = len1; i < len2; i++) {
            // 已经过去的位置
            hash2[s2[i - len1] - 'a']--;
            // 当前位置
            hash2[s2[i] - 'a']++;
            if (hash1 == hash2) {
                return i - len1 + 1;
            }
        }
        return -1;
    }
};
