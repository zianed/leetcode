/**
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// 回溯
class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        int n = digits.size();
        string s;
        backtrack(0, digits, s, res);
        return res;
    }
    void backtrack(int i, string & digits, string s, vector<string> &res)
    {
        if (i == digits.size()) {
            res.push_back(s);
            return;
        }
        for (char c : chars[digits[i] - '2']) {
            backtrack(i + 1, digits, s + c, res);
        }
    }
    vector<string> chars = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        
        vector<string> cVec = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int n = digits.size();
        string s(n, 0);
        backtrack(0, s, digits, cVec, res);
        return res;
    }
    
    void backtrack(int i, string &s, const string& digits, const vector<string>& cVec, vector<string> &res) {
        if (i == s.size()) {
            res.push_back(s);
            return;
        }
        
        for(char c : cVec[digits[i]-'2']) {
            s[i] = c;
            backtrack(i+1, s, digits, cVec, res);
        }
    }
};

// 循环处理
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> vecs;
        for (char c : digits) {
            // cout << c << endl;
            if (vecs.empty()) {
                vector<char> &vec = veChar[c - '0' - 2];
                for (char t : vec) {
                    string s;
                    s.append(1, t);
                    // cout << "=>" << s << endl;
                    vecs.push_back(s);
                }
                continue;
            }
            
            vector<string> vecsTmp;
            vector<char> &vec = veChar[c - '0' - 2];
            for (char y : vec) {
                // cout << "=>" <<y << endl;
                for (string s : vecs) {
                    vecsTmp.push_back(s+ y);
                }
            }
            vecs.clear();
            vecs.swap(vecsTmp);
            
            // cout << vecs.size() << endl;
        }
        return vecs;
    }
    
private:
    vector<vector<char>> veChar = {
        {'a', 'b', 'c'}, 
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
};
