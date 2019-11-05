/**
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// 排序后做key计算，根据key来快速查找，而不是循环遍历
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> strGroup;
        map<string, vector<string>> strMap;
        for (string &str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            strMap[temp].push_back(str);
        }

        for (auto it : strMap) {
            strGroup.push_back(it.second);
        }
        return strGroup;
    }
};

// 暴力破解，超时
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> strGroup;
        for (string &str : strs) {
            int pos = -1;
            for (int i = 0; i < strGroup.size(); i++) {
                string &key = strGroup[i][0];
                if (isAnagram(key, str)) {
                    pos = i;
                    break;
                }
            }
            if (pos != -1) {
                strGroup[i].push_back(str);
            } else {
                strGroup.push_back(vector<string>{str});
            }
        }
        return strGroup;
    }

    bool isAnagram(string s, string t) {
        vector<int> charArray(26, 0);
        for (char c : s) {
            charArray[c - 'a']++;
        }
        for (char c : t) {
            charArray[c - 'a']--;
        }
        for (int i = 0; i < charArray.size(); i++) {
            if (charArray[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
