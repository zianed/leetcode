/**
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/


/**
子集的个数是2的次方个数
**/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        for (int mask = 0; mask < (1 << len); mask++) {
            vector<int> vec;
            for (int i = 0; i < len; i++) {
                if (mask & (1 << i)) {
                    vec.push_back(nums[i]);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};



/**
回溯法超时，存在顺序时可以处理，不存在顺序时，需要考虑重复

**/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(vector<int>{});
        int len = nums.size();
        if (len == 0) {
            return res;
        }
        for (int i = 1; i < len; i++) {
           vector<int> vec;
           vector<bool> visited(len, false);
           for (int j = 0; j < nums.size(); j++) {
                backtrace(res, nums, visited, i,vec, j);
           }
        }
        res.push_back(nums);
        return res;
    }
    
    void backtrace(vector<vector<int>> &res, vector<int>& nums, vector<bool> visited, int len,vector<int> vec, int i) {
        if (visited[i]) {
            return;
        }
        if (vec.size() == len) {
            sort(vec.begin(), vec.end());
            if (res.find(vec) == res.end()) {
                res.push_back(vec);
            }
            return;
        }
        visited[i] = true;
        vec.push_back(nums[i]);
        for (int j = 0; j < nums.size(); j++) {
            if (!visited[j]) {
                backtrace(res, nums, visited, len, vec, j);
            }
        }
    }
};