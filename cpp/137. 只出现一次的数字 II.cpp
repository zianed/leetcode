/**
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,3,2]
输出: 3
示例 2:

输入: [0,1,0,1,0,1,99]
输出: 99

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/


// 使用map存储次数的操作方法
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> mapV;
        for (int i : nums) {
            auto it = mapV.find(i);
            if (it == mapV.end()) {
                mapV[i] = 1; 
                continue;
            }
            if (it->second == 2) {
                mapV.erase(it);
            } else {
                mapV[i] = 2;
            }
        }
        return mapV.begin()->first;
    }
};

// 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int see_one = 0;
		int see_two = 0;
		for (int num : nums) {
			see_one = ~see_two & (see_one ^ num);
			see_two = ~see_one & (see_two ^ num);
		}
		return see_one;
    }
};

